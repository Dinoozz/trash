/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** broadcast
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../../include/server/server.h"
#include "../../../include/server/server.h"

int cardinal_turn(int cardinal, int direction)
{
    return cardinal + (2 * direction) % 9;
}

int reverse_sign(int vector)
{
    if (vector >= 0)
        return -1;
    return 1;
}

int get_cardinal(int x_vector, int y_vector)
{
    int cardinal[3][3] = {2, 1, 8,
                        3, 0, 7,
                        4, 5, 6};
    int i = 0;
    int j = 0;

    if (x_vector < 0)
        j = 2;
    else
        j = x_vector == 0 ? 1: 0;

    if (y_vector < 0)
        i = 2;
    else
        i = y_vector == 0 ? 1: 0;
    return cardinal[i][j];
}

int bc_direcion(Client *client_recevier, Client *clien_sender, Server_t *server)
{
    int x_vector = client_recevier->user.x - clien_sender->user.x;
    int y_vector = client_recevier->user.y - clien_sender->user.y;
    int card_before_turn = 0;

    if (abs(x_vector) > (server->width) / 2)
    {
        x_vector = (server->width - abs(x_vector)) * reverse_sign(x_vector);
    }
    if (abs(y_vector) > (server->height /2))
    {
        y_vector *= (server->height - abs(y_vector)) * reverse_sign(y_vector);
    }
    card_before_turn = get_cardinal(x_vector, y_vector);
    return  cardinal_turn(card_before_turn, client_recevier->user.direction);
}

void broadcast(Server_t *server, Client *clients, Client *client, char *message)
{
    char *str = malloc(sizeof(char) * 1024);
    for (int i = 0; i < server->actual ; i++)
    {
        if (strcmp(clients[i].name, client->name) == 0)
        {
            continue;
        }
        sprintf(str, "message %i %s \n", bc_direcion(&clients[i],
        client, server), message);
        write_client(clients[i].sock, str);
    }
}