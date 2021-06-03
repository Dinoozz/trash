/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** init_objectif
*/

#include "../../include/client/client.h"

void init_obj1(player_t *player)
{
    player->lvl = 1;
    player->food = 1260;
    player->objectif.allie = 1;
    player->objectif.deraumere = 0;
    player->objectif.linemate = 1;
    player->objectif.mendiane = 0;
    player->objectif.phiras = 0;
    player->objectif.sibur = 0;
    player->objectif.thystame = 0;
}

void init_obj2(player_t *player)
{
    player->objectif.allie = 2;
    player->objectif.deraumere = 1;
    player->objectif.linemate = 1;
    player->objectif.mendiane = 0;
    player->objectif.phiras = 0;
    player->objectif.sibur = 1;
    player->objectif.thystame = 0;
}

void init_obj3(player_t *player)
{
    player->objectif.allie = 2;
    player->objectif.deraumere = 0;
    player->objectif.linemate = 2;
    player->objectif.mendiane = 0;
    player->objectif.phiras = 2;
    player->objectif.sibur = 1;
    player->objectif.thystame = 0;
}

void init_obj4(player_t *player)
{
    player->objectif.allie = 4;
    player->objectif.deraumere = 1;
    player->objectif.linemate = 1;
    player->objectif.mendiane = 0;
    player->objectif.phiras = 1;
    player->objectif.sibur = 2;
    player->objectif.thystame = 0;
}

void init_obj5(player_t *player)
{
    player->objectif.allie = 4;
    player->objectif.deraumere = 2;
    player->objectif.linemate = 1;
    player->objectif.mendiane = 3;
    player->objectif.phiras = 0;
    player->objectif.sibur = 1;
    player->objectif.thystame = 0;
}