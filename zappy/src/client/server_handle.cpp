/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server_handle
*/

#include "../../include/client/client.h"
#include <string>

int read_server(SOCKET sock, char *buffer)
{
    int n = 0;

    if ((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0) {
        perror("recv error");
        exit(errno);
    }
    buffer[n] = 0;
    
    return n;
}

void write_server(SOCKET sock, const char *buffer)
{
    if (send(sock, buffer, std::string(buffer).length(), 0) < 0) {
        perror("send error");
        exit(errno);
    }
} 