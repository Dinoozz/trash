/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** ia
*/

#include "../../include/client/client.h"
#include <iostream>
#include <string>

int get_objectif(SOCKET sock, fd_set rdfs)
{
    char response[1024];
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;   
    sleep(1);
    write_server(sock, "Inventory");
    if (FD_ISSET(sock, &rdfs)) {
        int n = read_server(sock, response);
        if (n == 0) { /* server down */
            printf("Server disconnected !\n");
            return -1;
        }
        char **parsed_response = parse_string(response);
        for (int i = 0; parsed_response[i]; i++)
            printf("%s\n", parsed_response[i]);
    }
}