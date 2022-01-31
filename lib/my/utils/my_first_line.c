/*
** EPITECH PROJECT, 2022
** my lib
** File description:
** get first line
*/

#include <stdlib.h>

#include "my.h"

int get_first_line_length(char *text)
{
    int size = 0;

    if (text == NULL)
        return -1;
    while (text[size] != '\0')
        if (text[size] != '\n')
            size++;
        else
            return size;
    return size;
}

char *my_get_first_line(char *text)
{
    int size = get_first_line_length(text);
    char *first_line = NULL;

    if (size == -1)
        return NULL;
    if ((first_line = my_malloc(size + 1, text)) == NULL)
        return NULL;
    first_line[size] = '\0';
    return first_line;
}
