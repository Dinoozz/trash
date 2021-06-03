/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** invotory
*/

#include "../../../include/client/client.h"
#include "../../../include/server/server.h"

char *inventory(Client *client)
{
    char *string = malloc(1024);
    printf("zoul\n");
    sprintf(string,"[food %d, sibur %d, phiras %d, deraumere %d, linemate %d, mendiane %d, thystame %d]",
    client->user.food, client->user.sibur, client->user.phiras,
    client->user.deraumere, client->user.linemate, client->user.mendiane,
    client->user.thystame);
    printf("ette\n");
    return (string);
}