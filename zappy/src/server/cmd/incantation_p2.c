/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** check_stones
*/

#include "../../../include/server/server.h"

int check_lvl_5(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x &&
        clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt >= 4 && tile[client->user.y][client->user.x].linemate >= 1
    && tile[client->user.y][client->user.x].deraumere >= 2
    && tile[client->user.y][client->user.x].sibur >= 1
    && tile[client->user.y][client->user.x].mendiane >= 3) {
        return (5);
    }
    return (-1);
}

int check_lvl_6(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x &&
        clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt > 6 && tile[client->user.y][client->user.x].linemate >= 1
    && tile[client->user.y][client->user.x].deraumere >= 2
    && tile[client->user.y][client->user.x].sibur >= 3
    && tile[client->user.y][client->user.x].phiras >= 1) {
        return (6);
    }
    return (-1);
}

int check_lvl_7(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x &&
        clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt > 6 && tile[client->user.y][client->user.x].linemate >= 3
    && tile[client->user.y][client->user.x].deraumere >= 2
    && tile[client->user.y][client->user.x].sibur >= 2
    && tile[client->user.y][client->user.x].mendiane >= 2
    && tile[client->user.y][client->user.x].thystame >= 1
    && tile[client->user.y][client->user.x].phiras >= 1) {
        return (7);
    }
    return (-1);
}