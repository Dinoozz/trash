/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** init_server
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/server/server.h"
#include "../../include/client/client.h"

void print_help()
{
    printf("USAGE: ./zappy_server -p port -x width ");
    printf("-y height -n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\tis the port number\n");
    printf("\twidth\tis the width of the world\n");
    printf("\theight\tis the height of the world\n");
    printf("\tnameXt\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\tis the reciprocal of time unit for execution of actions\n");
}

void print_server_content(Server_t *server)
{
    printf("Port: %li\n", server->port);
    printf("Width: %li\n", server->width);
    printf("Height: %li\n", server->height);
    printf("Clientsnb: %li\n", server->clientsnb);
    printf("Freq: %li\n", server->freq);
}

void init_server(Server_t *server,  int argc, char **argv)
{
    int opt;
    int index;
    char *next;

    while ((opt = getopt(argc, argv, "p:x:y:n:c:f:h")) != -1)
    {
        switch(opt)
        {
            case 'p':
                server->port = atoi(optarg);
                break;
            case 'x':
                server->width = atoi(optarg);
                break;
            case 'y':
                server->height = atoi(optarg);
                break;
            case 'n':
                index = optind-1;
                while (index < argc) {
                    next = argv[index];
                    if (next[0] != '-')
                        index++;
                    else
                        break;
                }
                server->nbteams = index - (optind - 1);
                server->nameX = malloc(sizeof(char *) * (server->nbteams + 1));
                if (!server->nameX)
                    write(2, "malloc error\n", 15);
                for (int i = 0; i < server->nbteams; i++)
                    server->nameX[i] = strdup(argv[i + (optind - 1)]);
                server->nameX[server->nbteams] = NULL;
            case 'c':
                server->clientsnb = atoi(optarg);
                break;
            case 'f':
                server->freq = atoi(optarg);
                break;
            case 'h':
                print_help();
                exit(0);
        }
    }
    if (server->width && server->height)
        server->map = map_gen(server->width, server->height);
    server->actual = 0;
    return;
}
