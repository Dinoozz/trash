/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include "../../include/server/server.h"

void app(Server_t *server)
{
    SOCKET sock = init_server_connection(server->port);
    char buffer[BUF_SIZE];
    int max = sock;
    Client clients[MAX_CLIENTS];

    fd_set rdfs;

    int food_count = 0;

    while (1) {

        usleep((1 / server->freq) / CLOCKS_PER_SEC);

        int i = 0;
        FD_ZERO(&rdfs);

        FD_SET(STDIN_FILENO, &rdfs);
        FD_SET(sock, &rdfs);

        for (i = 0; i < server->actual; i++)
            FD_SET(clients[i].sock, &rdfs);

        if (select(max + 1, &rdfs, NULL, NULL, NULL) == -1) {
            perror("select error");
            exit(errno);
        }

        if (FD_ISSET(STDIN_FILENO, &rdfs))
            break;
        else if (FD_ISSET(sock, &rdfs)) {
            SOCKADDR_IN csin = { 0 };
            size_t sinsize = sizeof(csin);
            int csock = accept(sock, (SOCKADDR *)&csin, (socklen_t *)&sinsize);

            if (csock == SOCKET_ERROR) {
                perror("accept error");
                continue;
            }
            if (read_client(csock, buffer) == -1)
                continue;

            max = csock > max ? csock : max;

            FD_SET(csock, &rdfs);

            Client c = { csock };
            strncpy(c.name, buffer, BUF_SIZE - 1);
            init_user(&c);

            clients[server->actual] = c;
            server->actual++;
        } else {

            int i = 0;
            for (i = 0; i < server->actual; i++) {
                if (FD_ISSET(clients[i].sock, &rdfs)) {

                    Client client = clients[i];

                    if (client.user.count && client.user.count >= 126) {
                        client.user.food -= 1;
                        client.user.count = 0;
                    }
                    clients[i].user.count += 1;

                    int c = read_client(clients[i].sock, buffer);
                    if (c == 0) {
                        closesocket(clients[i].sock);
                        remove_client(clients, i, &server->actual);
                        strncpy(buffer, client.name, BUF_SIZE - 1);
                        strncat(buffer, " disconnected !",
                        BUF_SIZE - strlen(buffer) - 1);
                        send_message_to_all_clients(clients, client,
                        server->actual, buffer, 1);
                    } else if (time(NULL) - client.start >=
                                client.cycle / server->freq)
                        check_command(buffer, clients, &clients[i], server);
                    break;
                }
            }
        }
    }
    clear_clients(clients, server->actual);
    closesocket(sock);
}

void send_message_to_all_clients(Client *clients, Client sender,
                                int actual, const char *buffer,
                                char from_server)
{
    int i = 0;
    char message[BUF_SIZE];
    message[0] = 0;
    for (i = 0; i < actual; i++) {
        if (sender.sock != clients[i].sock) {
            if (from_server == 0) {
                strncpy(message, sender.name, BUF_SIZE - 1);
                strncat(message, " : ", sizeof(message) - strlen(message) - 1);
            }
        strncat(message, buffer, sizeof(message) - strlen(message) - 1);
        write_client(clients[i].sock, message);
        }
    }
}

int init_server_connection(int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sin = { 0 };

    if (sock == INVALID_SOCKET) {
        perror("socket error");
        exit(errno);
    }

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;

    if (bind(sock, (SOCKADDR *) &sin, sizeof(sin)) == SOCKET_ERROR) {
        perror("bind error");
        exit(errno);
    }

    if (listen(sock, MAX_CLIENTS) == SOCKET_ERROR) {
        perror("listen error");
        exit(errno);
    }

    return sock;
}

int main(int argc, char **argv)
{
    Server_t server;
    init_server(&server, argc, argv);


    app(&server);


    return EXIT_SUCCESS;
}