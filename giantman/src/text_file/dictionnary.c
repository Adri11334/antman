/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** dictionary
*/

#include <stdlib.h>

#include "giantman.h"

char **get_dictionnary(char *text)
{
    char *first_line = NULL;
    char **dictionnary = NULL;

    if (text == NULL)
        return NULL;
    if ((first_line = my_get_first_line(text)) == NULL)
        return NULL;
    if ((dictionnary = my_str_to_words_array(first_line)) == NULL)
        return NULL;
    return dictionnary;
}
