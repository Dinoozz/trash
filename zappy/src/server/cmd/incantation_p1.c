/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** level_up for server
*/

#include "../../../include/server/server.h"

int check_lvl_1(Client *clients, Client *client, Tile_t **tile)
{
    if (tile[client->user.y][client->user.x].linemate >= 1) {
        return (1);
    }
    return (-1);

}

int check_lvl_2(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x
        && clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt >= 2 && tile[client->user.y][client->user.x].linemate >= 1
    && tile[client->user.y][client->user.x].deraumere >= 1
    && tile[client->user.y][client->user.x].sibur >= 1) {
        return (2);
    }
    return (-1);
}

int check_lvl_3(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x
        && clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt >= 2 && tile[client->user.y][client->user.x].linemate >= 2
    && tile[client->user.y][client->user.x].sibur >= 1
    && tile[client->user.y][client->user.x].phiras >= 2) {
        return (3);
    }
    return (-1);
}

int check_lvl_4(Client *clients, Client *client, Tile_t **tile,
                Server_t *server)
{
    int cnt = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x
        && clients[i].user.y == client->user.y &&
        clients[i].user.lvl == client->user.lvl)
            cnt++;
    }
    if (cnt >= 4 && tile[client->user.y][client->user.x].linemate >= 1
    && tile[client->user.y][client->user.x].deraumere >= 1
    && tile[client->user.y][client->user.x].sibur >= 2
    && tile[client->user.y][client->user.x].phiras >= 1) {
        return (4);
    }
    return (-1);
}

int check_incantation(Client *clients, Client *client, Tile_t **tile,
                        Server_t *server)
{
    int test = client->user.lvl;
    switch (test)
    {
    case 1:
        return (check_lvl_1(clients, client, tile));
    case 2:
        return (check_lvl_2(clients, client, tile, server));
    case 3:
        return (check_lvl_3(clients, client, tile, server));
    case 4:
        return (check_lvl_4(clients, client, tile, server));
    case 5:
        return (check_lvl_5(clients, client, tile, server));
    case 6:
        return (check_lvl_6(clients, client, tile, server));
    case 7:
        return (check_lvl_7(clients, client, tile, server));
    }
}