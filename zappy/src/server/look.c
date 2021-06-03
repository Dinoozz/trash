/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** look
*/

#include "../../include/server/server.h"

char *look_right(Client client, Client *clients, Server_t *server)
{
    char *res = malloc(4096);
    int offset = 0;
    int k;
    int l;
    int j;

    res[0] = '\0';
    strcat(res, "[");
    for (int i = 0; i <= client.user.lvl; i++, offset++) {
        k = ((i + client.user.x) % server->width < 0) ?
        (i + client.user.x) % server->width + server->width :
        i + client.user.x % server->width;
        for (j = client.user.y - offset; j <= client.user.y + offset; j++) {
            l = (j % server->height < 0) ?
            j % server->height + server->height : j % server->height;
            if (i > 0)
                strcat(res, ", ");
            if (server->map[l][k + client.user.y].deraumere >= 1)
                strcat(res, "deraumere ");
            if (server->map[l][k].linemate >= 1)
                strcat(res, "linemate ");
            if (server->map[l][k].mendiane >= 1)
                strcat(res, "mendiane ");
            if (server->map[l][k].phiras >= 1)
                strcat(res, "phiras ");
            if (server->map[l][k].sibur >= 1)
                strcat(res, "sibur ");
            if (server->map[l][k].thystame >= 1)
                strcat(res, "thystame ");
            if (server->map[l][k].food >= 1)
                strcat(res, "food ");
            for (int m = 0; m < server->actual; m++) {
                if (clients[m].user.x == k && clients[m].user.y == l)
                    strcat(res, "player ");
            }
        }
    }
    strcat(res, "]\n");
    return res;
}

char *look_left(Client client, Client *clients, Server_t *server)
{
    char *res = malloc(4096);
    int offset = 0;
    int k;
    int l;
    int j;

    res[0] = '\0';
    strcat(res, "[");
    for (int i = 0; i <= client.user.lvl; i++, offset++) {
        k = ((client.user.x - i) % server->width < 0) ?
        (client.user.x - i) % server->width + server->width :
        (client.user.x - i) % server->width;
        for (j = client.user.y + offset; j >= client.user.y - offset; j--) {
            l = (j % server->height < 0) ?
            j % server->height + server->height : j % server->height;
            if (i > 0)
                strcat(res, ", ");
            if (server->map[l][k].deraumere >= 1)
                strcat(res, "deraumere ");
            if (server->map[l][k].linemate >= 1)
                strcat(res, "linemate ");
            if (server->map[l][k].mendiane >= 1)
                strcat(res, "mendiane ");
            if (server->map[l][k].phiras >= 1)
                strcat(res, "phiras ");
            if (server->map[l][k].sibur >= 1)
                strcat(res, "sibur ");
            if (server->map[l][k].thystame >= 1)
                strcat(res, "thystame ");
            if (server->map[l][k].food >= 1)
                strcat(res, "food ");
            for (int m = 0; m < server->actual; m++) {
                if (clients[m].user.x == k && clients[m].user.y == l)
                    strcat(res, "player ");
            }
        }
    }
    strcat(res, "]\n\0");
    return res;
}

char *look_forward(Client client, Client *clients, Server_t *server)
{
    char *res = malloc(4096);
    int k;
    int l;

    res[0] = '\0';
    strcat(res, "[");
    for (int i = 0; i <= client.user.lvl; i++) {
        l = ((client.user.y - i) % server->height < 0) ?
        (client.user.y - i) % server->height + server->height :
        (client.user.y - i) % server->height;
        for (int j = client.user.x - i; j <= client.user.x + i; j++) {
            k = (j % server->width < 0) ?
            (j % server->width) + server->width : (j % server->width);
            if (i > 0)
                strcat(res, ", ");
            if (server->map[l][k].deraumere >= 1)
                strcat(res, "deraumere ");
            if (server->map[l][k].linemate >= 1)
                strcat(res, "linemate ");
            if (server->map[l][k].mendiane >= 1)
                strcat(res, "mendiane ");
            if (server->map[l][k].phiras >= 1)
                strcat(res, "phiras ");
            if (server->map[l][k].sibur >= 1)
                strcat(res, "sibur ");
            if (server->map[l][k].thystame >= 1)
                strcat(res, "thystame ");
            if (server->map[l][k].food >= 1)
                strcat(res, "food ");
            for (int m = 0; m < server->actual; m++) {
                if (clients[m].user.x == k && clients[m].user.y == l)
                    strcat(res, "player ");
            }
        }
    }
    strcat(res, "]\n");
    return res;
}

char *look_backward(Client client, Client *clients, Server_t *server)
{
    char *res = malloc(4096);
    int offset = 0;
    int k;
    int l;

    res[0] = '\0';
    strcat(res, "[");
    for (int i = 0; i <= client.user.lvl; i++, offset++) {
        l = ((i + client.user.y) % server->height < 0) ?
        (i + client.user.y) % server->height + server->height :
        (i + client.user.y) % server->height;
        for (int j = client.user.x + offset; j >= client.user.x - offset; j--) {
            k = (j % server->width < 0) ?
            (j % server->width) + server->width : (j % server->width);
            if (i > 0)
                strcat(res, ", ");
            if (server->map[l][k].deraumere >= 1)
                strcat(res, "deraumere ");
            if (server->map[l][k].linemate >= 1)
                strcat(res, "linemate ");
            if (server->map[l][k].mendiane >= 1)
                strcat(res, "mendiane ");
            if (server->map[l][k].phiras >= 1)
                strcat(res, "phiras ");
            if (server->map[l][k].sibur >= 1)
                strcat(res, "sibur ");
            if (server->map[l][k].thystame >= 1)
                strcat(res, "thystame ");
            if (server->map[l][k].food >= 1)
                strcat(res, "food ");
            for (int m = 0; m < server->actual; m++) {
                if (clients[m].user.x == k && clients[m].user.y == l)
                    strcat(res, "player ");
            }
        }
    }
    strcat(res, "]\n");
    return res;
}

char *look_arround(Client client, Client * clients, Server_t *server)
{
    switch (client.user.direction) {
        case 0:
            return look_forward(client, clients, server);
        case 1:
            return look_right(client, clients, server);
        case 2:
            return look_backward(client, clients, server);
        case 3:
            return look_left(client, clients, server);
        default:
            return NULL;
    }
}