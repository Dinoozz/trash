/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** forward
*/

#include "../../../include/server/server.h"

void move_user(Server_t *server, Client *client, int a, int b)
{
    client->user.y += a;
    client->user.x += b;

    if (client->user.y < 0)
        client->user.y = client->user.y + server->height;
    if (client->user.x < 0)
        client->user.x = client->user.x + server->width;
    if (client->user.x >= server->width)
        client->user.x = 0;
    if (client->user.y >= server->height)
        client->user.y = 0;
}

void forward(Server_t *server, Client *client)
{
    switch (client->user.direction)
    {
    case (0):
        move_user(server, client, -1, 0);
        break;
    case (1):
        move_user(server, client, 0, 1);
        break;
    case (2):
        move_user(server, client, 1, 0);
        break;
    case (3):
        move_user(server, client, 0, -1);
        break;
    default:
        return;
    }
}