/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** eject
*/

#include "../../../include/server/server.h"

int eject_user_x(Server_t *server, Client *client, int x, Client *clients)
{
    int has_pushed = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x &&
        clients[i].user.y == client->user.y &&
        strcmp(clients[i].name, client->name) != 0) {
            clients[i].user.x += x;
        }
    }
    return (has_pushed);
}

int eject_user_y(Server_t *server, Client *client, int y, Client *clients)
{
    int has_pushed = 0;

    for (int i = 0; i < server->actual; i++) {
        if (clients[i].user.x == client->user.x &&
        clients[i].user.y == client->user.y
        && strcmp(clients[i].name, client->name) != 0) {
            clients[i].user.y += y;
            has_pushed = 1;
        }
    }
    return (has_pushed);
}

int eject(Server_t *server, Client *client, Client *clients)
{
    switch (client->user.direction)
    {
    case (0):
        return (eject_user_y(server, client, -1, clients));
    case (1):
        return (eject_user_x(server, client, 1, clients));
    case (2):
        return (eject_user_y(server, client, 1, clients));
    case (3):
        return (eject_user_x(server, client, -1, clients));
    default:
        return (0);
    }
}