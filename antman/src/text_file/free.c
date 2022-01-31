/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** free
*/

#include <stddef.h>
#include <stdlib.h>

int free_double_char(char **arr)
{
    int free_index = 0;
    if (arr == NULL)
        return -1;
    while (arr[free_index] != NULL) {
        free(arr[free_index]);
        free_index++;
    }
    free(arr);
    return 0;
}
