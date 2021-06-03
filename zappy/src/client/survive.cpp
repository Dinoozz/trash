/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** survive
*/

#include "../../include/client/client.h"

void search_food(SOCKET sock)
{
    char buf[1024];

    write_server(sock, "Look\n");
    read_server(sock, buf);
}