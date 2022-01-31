/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** main.c
*/

#include <stdlib.h>

#include "giantman.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    return giantman_base(argv[1], my_getnbr(argv[2]));
}
