/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** set
*/

#include "../../../include/server/server.h"

int set_stone(Client *client, Server_t *server, char *obj)
{
    if (strcmp(obj, "mendiane") == 0 && client->user.mendiane > 0) {
        server->map[client->user.y][client->user.x].mendiane += 1;
        client->user.mendiane -= 1;
    } else if (strcmp(obj, "phiras") == 0 && client->user.phiras > 0){
        server->map[client->user.y][client->user.x].phiras += 1;
        client->user.phiras -= 1;
    } else if (strcmp(obj, "thystame") == 0 && client->user.thystame > 0){
        server->map[client->user.y][client->user.x].thystame += 1;
        client->user.thystame -= 1;
    } else
        return -1;
    return (1);
}

int set(Client *client, Server_t *server, char *obj)
{
    if (strcmp(obj, "linemate") == 0 && client->user.linemate > 0) {
        server->map[client->user.y][client->user.x].linemate += 1;
        client->user.linemate -= 1;
    } else if (strcmp(obj, "deraumere") == 0 && client->user.deraumere > 0) {
        server->map[client->user.y][client->user.x].deraumere += 1;
        client->user.deraumere -= 1;
    } else if (strcmp(obj, "sibur") == 0 && client->user.sibur > 0) {
        server->map[client->user.y][client->user.x].sibur += 1;
        client->user.sibur -= 1;
    } else
        set_stone(client, server, obj);
    return (1);
}