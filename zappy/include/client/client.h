/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#define CRLF     "\r\n"
#define PORT     1977

#define BUF_SIZE 1024


typedef struct objectif_s
{
    char *team;
    int lvl;
    int x;
    int y;
    int direction;
    int food;
    int count;
    int allie;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
}objectif_t;

typedef struct player_s
{
    char *team;
    int lvl;
    int food;

    objectif_t objectif;
}player_t;

typedef struct data_s
{
    char *ip_server;
    char *port_server;
}data_t;



void apps(const char *address, const int port, const char *name);
int init_client_connection(const char *address, int port);
int read_server(SOCKET sock, char *buffer);
void write_server(SOCKET sock, const char *buffer);
void init_obj1(player_t *player);
void init_obj2(player_t *player);
void init_obj3(player_t *player);
void init_obj4(player_t *player);
void init_obj5(player_t *player);
void init_obj6(player_t *player);
void init_obj7(player_t *player);
char **parse_string(const char *string);
int get_objectif(SOCKET sock, fd_set rdfs);
int split_process(player_t player, data_t servdata);

#endif /* guard */