/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "../../include/client/client.h"

char **parse_string(const char *string)
{
    int count = 1;
    char **array;
    int temp = 0;
    int counter = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ',')
            count++;
    }
    array = (char **)malloc((count + 1) * sizeof(char *));
    array[count] = NULL;
    count = 0;
    for (int i = 1; string[i] != '\0' && string[i] != '\n'; i++) {
        if (string[i] == ',' || string[i] == ']') {
            array[temp] = (char *)malloc((count + 2) * sizeof(char));
            count = 0;
            for (; string[i - 1] != ',' && string[i - 1] != '['; i--);
            for (; string[i] != ',' && string[i] != ']'; i++) {
                array[temp][counter] = string[i];
                counter++;
            }
            array[temp][counter] = '\0';
            counter = 0;
            temp++;
            i++;
        } else
            count++;
        if (string[i] == '\0' || string[i] == '\n')
            break;
    }
    return (array);
}

void apps(const char *address, const int port, const char *name)
{
    SOCKET sock = init_client_connection(address, port);
    char buffer[BUF_SIZE];
    player_t player;
    fd_set rdfs;
    data_t servdata;
    int check_fork = 0;

    servdata.ip_server = strdup(address);
    servdata.port_server = (char *)std::malloc(5);
    sprintf(servdata.port_server, "%d", port);
    init_obj1(&player);
    write_server(sock, name); /* send our name */

    while (1) {

        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs); /* add STDIN_FILENO */
        FD_SET(sock, &rdfs); /* add the socket */

        if (select(sock + 1, &rdfs, NULL, NULL, NULL) == -1) {
            perror("select()");
            exit(errno);
        }
        if (player.food <= 0)
            break;
        /* something from standard input : i.e keyboard */
        if (FD_ISSET(STDIN_FILENO, &rdfs)) {
            fgets(buffer, BUF_SIZE - 1, stdin);
            char *message = NULL;
            message = strstr(buffer, "\n");
            if (message != NULL)
               *message = 0;
            else
               buffer[BUF_SIZE - 1] = 0; // fclean
            if (strcmp(buffer, "Fork") == 0)
                check_fork = 1;
            write_server(sock, buffer);
        }
        else if (FD_ISSET(sock, &rdfs)) {
            int n = read_server(sock, buffer);
            if (strcmp(buffer, "ok") == 0 && check_fork == 1) {
                check_fork = 0;
                split_process(player, servdata);
            }
            if (n == 0) { /* server down */
                printf("Server disconnected !\n");
                break;
            }
            
            puts(buffer);
        }
    }

   closesocket(sock);
}

int init_client_connection(const char *address, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sin = { 0 };
    struct hostent *hostinfo;

    if (sock == INVALID_SOCKET) {
        perror("socket error");
        exit(errno);
    }

    hostinfo = gethostbyname(address);

    if (hostinfo == NULL) {
        fprintf (stderr, "Unknown host %s.\n", address);
        exit(EXIT_FAILURE);
    }

    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;

    if (connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        perror("connect error");
        exit(errno);
    }

    return sock;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage : %s [address] [port] [pseudo]\n", argv[0]);
        return EXIT_FAILURE;
    }
    apps(argv[1], atoi(argv[2]), argv[3]);

    return EXIT_SUCCESS;
}