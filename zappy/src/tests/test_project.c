/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** test_project
*/

#include <criterion/criterion.h>
#include "../../include/client/client.h"
#include "../../include/server/server.h"

Test(criterion_test, test) {

    cr_expect(strlen("Test") == 4);
    cr_expect(strlen("Hello") == 4);
    cr_assert(strlen("") == 0);
}

Test(init_server_connection, no_error_open) {

    int port = 4242;

    cr_assert(init_server_connection(port) == 0);

}