/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client_handle
*/

#include "../../include/server/server.h"

void clear_clients(Client *clients, int actual)
{
    int i = 0;
    for (i = 0; i < actual; i++)
        closesocket(clients[i].sock);
}

void remove_client(Client *clients, int to_remove, int *actual)
{
    memmove(clients + to_remove, clients + to_remove + 1,
    (*actual - to_remove - 1) * sizeof(Client));

    (*actual)--;
}

int read_client(SOCKET sock, char *buffer)
{
    int n = 0;

    if ((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0) {
        perror("recv error");
    }
    buffer[n] = 0;

    printf("%s\n", buffer);

    return n;
}

void write_client(SOCKET sock, const char *buffer)
{
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        exit(errno);
    }
}