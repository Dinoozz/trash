/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take
*/

#include "../../../include/server/server.h"

int take_stone(Client *client, Server_t *server, char *obj)
{
    if (strcmp(obj, "mendiane") == 0 &&
    server->map[client->user.y][client->user.x].mendiane > 0) {
        server->map[client->user.y][client->user.x].mendiane -= 1;
        client->user.mendiane += 1;
    } else if (strcmp(obj, "phiras") == 0 &&
    server->map[client->user.y][client->user.x].phiras > 0){
        server->map[client->user.y][client->user.x].phiras -= 1;
        client->user.phiras += 1;
    } else if (strcmp(obj, "thystame") == 0 &&
    server->map[client->user.y][client->user.x].thystame > 0){
        server->map[client->user.y][client->user.x].thystame -= 1;
        client->user.thystame += 1;
    } else if (strcmp(obj, "food") == 0 &&
    server->map[client->user.y][client->user.x].food > 0){
        server->map[client->user.y][client->user.x].food -= 1;
        client->user.food += 1;
    } else
        return (0);
    return (1);
}

int take(Client *client, Server_t *server, char *obj)
{
    printf("%d/%d/%d/%d/%d/%d\n",
    server->map[client->user.y][client->user.x].linemate,
    server->map[client->user.y][client->user.x].deraumere,
    server->map[client->user.y][client->user.x].sibur,
    server->map[client->user.y][client->user.x].mendiane,
    server->map[client->user.y][client->user.x].phiras,
    server->map[client->user.y][client->user.x].thystame);
    printf("'%s'\n", obj);
    if (strcmp(obj, "linemate") == 0 &&
    server->map[client->user.y][client->user.x].linemate > 0) {
        server->map[client->user.y][client->user.x].linemate -= 1;
        client->user.linemate += 1;
    } else if (strcmp(obj, "deraumere") == 0 &&
    server->map[client->user.y][client->user.x].deraumere > 0) {
        server->map[client->user.y][client->user.x].deraumere -= 1;
        client->user.deraumere += 1;
    } else if (strcmp(obj, "sibur") == 0 &&
    server->map[client->user.y][client->user.x].sibur > 0) {
        server->map[client->user.y][client->user.x].sibur -= 1;
        client->user.sibur += 1;
    } else
        return (take_stone(client, server, obj));
    return (1);
}