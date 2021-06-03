/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#ifndef SERVER_H
#define SERVER_H
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
#define BUF_SIZE 1024

typedef struct
{
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int food;
}Tile_t;

typedef struct {
    size_t port;
    size_t width;
    size_t height;
    size_t nbteams;
    size_t clientsnb;
    size_t freq;
    int actual;
    char **nameX;
    Tile_t **map;
}Server_t;

typedef struct
{
    char *team;
    int lvl;
    int x;
    int y;
    int direction;
    int food;
    int count;

    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
}User_t;

typedef struct
{
    SOCKET sock;
    char name[BUF_SIZE];
    time_t start;
    float cycle;
    User_t user;
}Client;

#define CRLF        "\r\n"
#define PORT         1977
#define MAX_CLIENTS     100

#define BUF_SIZE    1024

#include "../client/client.h"

/**** CMD *****/

//broadcast.c

//connect_nbr.c
int connect_nbr(Client *clients, Client *client, Server_t *server);

//fork.c

//forward.c
void move_user(Server_t *server, Client *client, int a, int b);
void forward(Server_t *server, Client *client);

//incantation_p1.c
int check_lvl_1(Client *clients, Client *client, Tile_t **tile);
int check_lvl_2(Client *clients, Client *client, Tile_t **tile, Server_t *server);
int check_lvl_3(Client *clients, Client *client, Tile_t **tile, Server_t *server);
int check_lvl_4(Client *clients, Client *client, Tile_t **tile, Server_t *server);
int check_incantation(Client *clients, Client *client, Tile_t **tile, Server_t *server);

//incantation_p2.c
int check_lvl_5(Client *clients, Client *client, Tile_t **tile, Server_t *server);
int check_lvl_6(Client *clients, Client *client, Tile_t **tile, Server_t *server);
int check_lvl_7(Client *clients, Client *client, Tile_t **tile, Server_t *server);

//inventory.c
char *inventory(Client *client);

//left.c
void left(Server_t *server, Client *client);

//look.c
char *look_arround(Client client, Client * clients, Server_t *server);

//right.c
void right(Server_t *server, Client *client);

//set.c
int set_stone(Client *client, Server_t *server, char *obj);
int set(Client *client, Server_t *server, char *obj);

//take.c
int take_stone(Client *client, Server_t *server, char *obj);
int take(Client *client, Server_t *server, char *obj);

//broadcast.c
void broadcast(Server_t *server, Client *clients, Client *client,  char *message);


/**** SERVER *****/

//check_command.c
void check_food(Client *clients, Client *client, Server_t *server);
void check_command(const char *buffer, Client *clients, Client *client, Server_t *server);

//check_command_next.c
void check_set_take(const char *buffer, Client *clients, Client *client, Server_t *server);

//client_handle.c
void remove_client(Client *clients, int to_remove, int *actual);
void clear_clients(Client *clients, int actual);
int read_client(SOCKET sock, char *buffer);
void write_client(SOCKET sock, const char *buffer);

//eject.c
int eject(Server_t *server, Client *client, Client *clients);

//init.c
void init_user(Client *client);

//init_server.c
void print_server_content(Server_t *server);
void init_server(Server_t *server,  int argc, char **argv);

//main.c
static void app(Server_t *server);
static int init_server_connection(int port);
void send_message_to_all_clients(Client *clients, Client client, int actual, const char *buffer, char from_server);

//mapgen.c
Tile_t random_tile();
Tile_t **map_gen(int x, int y);

/***** STRUCT *****/

typedef struct {
    char *buffer;
    int time;
    int cmd;
}cmd_t;


#endif /* guard */
