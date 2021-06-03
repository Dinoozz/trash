/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** left
*/

#include "../../../include/client/client.h"
#include "../../../include/server/server.h"

void left(Server_t *server, Client *client)
{
    switch (client->user.direction)
    {
    case (0):
        client->user.direction = 3;
        break;
    case (1):
        client->user.direction -= 1;
        break;
    case (2):
        client->user.direction -= 1;
        break;
    case (3):
        client->user.direction -= 1;
        break;
    default:
        break;
    }
}