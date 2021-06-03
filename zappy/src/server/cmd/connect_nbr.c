/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** connect_nbr
*/

#include "../../../include/client/client.h"
#include "../../../include/server/server.h"

int connect_nbr(Client *clients, Client *client, Server_t *server)
{
    int players = 0;

    for (int i = 0; i < server->actual; i++) {
        if (strcmp(clients[i].user.team, client->user.team) == 0)
            players++;
    }
    return (server->clientsnb - players);
}