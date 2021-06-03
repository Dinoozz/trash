/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** check_command_next
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "../../include/server/server.h"

void check_eject(const char *buffer, Client *clients,
                    Client *client, Server_t *server)
{
    if (strcmp(buffer, "Eject") == 0) {
        if (eject(server, client, clients)) {
            write_client(client->sock, "ok\n");
            client->start = time(NULL);
            client->cycle = 7;
        } else
            write_client(client->sock, "ko\n");
    }
}

void check_incantation_command(const char *buffer, Client *clients,
                    Client *client, Server_t *server)
{
    if (strcmp(buffer, "Incantation") == 0) {
        int i = check_incantation(clients, client, server->map, server);
        if (i >= 0) {
            char str[1024];
            client->user.lvl++;
            sprintf(str, "Elevation underway\nCurrent level: %d\n", i);
            write_client(client->sock, str);
            client->start = time(NULL);
            client->cycle = 300;
        } else
            write_client(client->sock, "ko\n");
    } else
        check_eject(buffer, clients, client, server);
}

void check_look_broadcast(const char *buffer, Client *clients,
                    Client *client, Server_t *server)
{
    if (strcmp(buffer, "Look") == 0) {
        char *buff = look_arround(*client, clients, server);
        write_client(client->sock, buff);
        client->start = time(NULL);
        client->cycle = 7;
        free(buff);
    } else if (strncmp(buffer, "Broadcast", 9) == 0) {
        broadcast(server, clients, client, strchr(buffer, ' ') + 1);
        client->start = time(NULL);
        client->cycle = 7;
    } else
        check_incantation_command(buffer, clients, client, server);
}

void check_set_take(const char *buffer, Client *clients,
                    Client *client, Server_t *server)
{
    if (strncmp(buffer, "Take", 4) == 0) {
        if (take(client, server, strchr(buffer, ' ') + 1)) {
            write_client(client->sock, "ok\n");
            client->start = time(NULL);
            client->cycle = 7;
        } else
            write_client(client->sock, "ko\n");
    } else if (strncmp(buffer, "Set", 3) == 0) {
        if (set(client, server, strchr(buffer, ' ') + 1)) {
            write_client(client->sock, "ok\n");
            client->start = time(NULL);
            client->cycle = 7;
        } else
            write_client(client->sock, "ko\n");
    } else
        check_look_broadcast(buffer, clients, client, server);
}