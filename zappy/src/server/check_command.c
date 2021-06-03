/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "../../include/server/server.h"

// void check_food(Client *clients, Client *client, Server_t *server)
// {
//     for (int i = 0; i < server->actual; i++) {
//         if (clients[i].user.food <= 0) {
//             write_client(clients[i].sock, "Dead\n");
//             remove_client(clients, i, &server->actual);
//         }
//     }
// }

void check_inventory_connect_nbr(const char *buffer, Client *clients,
                    Client *client, Server_t *server)
{
    if (strcmp(buffer, "Inventory") == 0) {
        char *buff = inventory(client);
        write_client(client->sock, buff);
        client->start = time(NULL);
        client->cycle = 1;
        free(buff);
    } else if (strcmp(buffer, "Connect_nbr") == 0) {
        char str[1024];
        snprintf(str, 1024, "%d\n", connect_nbr(clients, client, server));
        write_client(client->sock, str);
    } else
        check_set_take(buffer, clients, client, server);
}

void check_right_left(const char *buffer, Client *clients, Client *client,
                    Server_t *server)
{
    if (strcmp(buffer, "Right") == 0) {
        right(server, client);
        write_client(client->sock, "ok\n");
        client->start = time(NULL);
        client->cycle = 7;
    } else if (strcmp(buffer, "Left") == 0) {
        left(server, client);
        write_client(client->sock, "ok\n");
        client->start = time(NULL);
        client->cycle = 7;
    } else
        check_inventory_connect_nbr(buffer, clients, client, server);
}

void check_Forward(const char *buffer, Client *clients, Client *client,
                    Server_t *server)
{
    if (strcmp(buffer, "Forward") == 0) {
        forward(server, client);
        write_client(client->sock, "ok\n");
        client->start = time(NULL);
        client->cycle = 7;
    } else 
        check_right_left(buffer, clients, client, server);
}

//check_food(clients, client, server);

void check_command(const char *buffer, Client *clients, Client *client,
                    Server_t *server)
{
    check_Forward(buffer, clients, client, server);
    if (strcmp(buffer, "Fork") == 0) {
        write_client(client->sock, "ok\n");
        client->start = time(NULL);
        client->cycle = 42;
    }
}