/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** manager
*/

#include <stdlib.h>

#include "giantman.h"

char **text_content(char *text)
{
    char **words_array = NULL;
    int f_line_size = 0;

    if (text == NULL)
        return NULL;
    f_line_size = get_first_line_length(text);
    for (int i = 0; i <= f_line_size; i++)
        text++;
    if ((words_array = my_str_to_words_array(text)) == NULL)
        return NULL;
    for (int i = 0; i <= f_line_size; i++)
        text--;
    free(text);
    return words_array;
}

int giantman_text_manager(char *text)
{
    char **dictionnary = NULL;
    char **text_array = NULL;

    if (text == NULL)
        return 84;
    if ((dictionnary = get_dictionnary(text)) == NULL)
        return 84;
    if ((text_array = text_content(text)) == NULL)
        return 84;
    return replacing_char_by_words(text_array, dictionnary);
}
