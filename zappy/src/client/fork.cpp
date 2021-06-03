/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** fork
*/
#include "../../include/client/client.h"
#include <sys/wait.h>
#include <sys/types.h>


int split_process(player_t player, data_t servdata)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        printf("fork failed\n");
        return 84;
    }
    else if (pid == 0) {
        status = execl("./zappy_ai", servdata.ip_server, servdata.port_server, player.team);
        exit(status);
    }   
}