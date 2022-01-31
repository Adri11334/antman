/*
** EPITECH PROJECT, 2022
** antman
** File description:
** main
*/

#include "antman.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    return antman_base(argv[1], my_getnbr(argv[2]));
}
