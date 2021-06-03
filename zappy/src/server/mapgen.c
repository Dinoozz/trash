/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** mapgen
*/

#include "../../include/server/server.h"

Tile_t random_tile(void)
{
    Tile_t new = (Tile_t){0, 0, 0, 0, 0, 0, 0};
    int random;
    for (int i = 0; i < 6; i++) {
        random = rand() % 100;
        if (random >= 0 && random < 10)
            new.deraumere = 1;
        else if (random >= 10 && random < 20)
            new.linemate = 1;
        else if (random >= 20 && random < 30)
            new.mendiane = 1;
        else if (random >= 30 && random < 40)
            new.phiras = 1;
        else if (random >= 40 && random < 50)
            new.sibur = 1;
        else if (random >= 50 && random < 60)
            new.thystame = 1;
        else if (random >= 60 && random < 70)
            new.food = 1;
        else
            continue;
    }
    return new;
}

Tile_t **map_gen(int x, int y)
{
    Tile_t **map = malloc(sizeof(Tile_t *) * y);
    srand(time(NULL));

    if (!map)
        exit(84);
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(Tile_t) * x);
        if (!map[i])
            exit(84);
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map[i][j] = random_tile();
        }
    }
    return map;
}