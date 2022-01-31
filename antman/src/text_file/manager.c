/*
** EPITECH PROJECT, 2022
** antman
** File description:
** manager
*/

#include "antman.h"
#include <stdlib.h>

int get_and_display_compression(int *count, char *text, char **words_arr)
{
    int unique_nb = 0;
    int replaced_words = 0;
    char **unique_words = NULL;
    char **words_to_replace = NULL;

    if ((unique_words = get_unique_words(words_arr, &unique_nb, count,
    my_strlen(text))) == NULL)
        return 84;
    free(text);
    words_to_replace = get_biggests(count, unique_words, unique_nb);
    free(count);
    if ((replaced_words = replace_uniques(words_arr, words_to_replace)) == 84)
        return 84;
    if (show_compressed_file(words_arr, words_to_replace) == 84)
        return 84;
    return 0;
}
