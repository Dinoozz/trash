/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** init
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "../../include/server/server.h"
#include "../../include/client/client.h"

void init_user(Client *client)
{
    client->user.sibur = 0;
    client->user.phiras = 0;
    client->user.deraumere = 0;
    client->user.linemate = 0;
    client->user.mendiane = 0;
    client->user.thystame = 0;
    client->user.lvl = 1;
    client->user.deraumere = 0;
    client->user.team = malloc(1024);
    client->user.team = strcpy(client->user.team, "team1");
    client->user.x = 5;
    client->user.y = 5;
    client->user.food = 100;
    client->user.count = 0;
    client->cycle = 0;
    client->start = time(NULL);
}