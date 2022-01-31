/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** replace_words
*/

#include "antman.h"
#include <stdlib.h>

int replace_word_by_char(char *original, char new)
{
    int original_len;
    int index = 0;

    if (original == NULL)
        return -1;
    original_len = my_strlen(original);
    original[index] = new;
    for (index = 1; index < original_len + 1; index++)
        original[index] = 0;
    return 0;
}

int replace_words(char new_word, char *original_word, char **words)
{
    if (!new_word || original_word == NULL)
        return 84;
    for (int i = 0; words[i] != NULL; i++) {
        if (my_strcmp(original_word, words[i]) == 0) {
            replace_word_by_char(words[i], new_word);
        }
    }
    return 0;
}

int replace_uniques(char **words, char **words_to_replace)
{
    char replace_char[] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };

    for (int i = 0; words_to_replace[i] != NULL; i++)
        if (replace_words(replace_char[i], words_to_replace[i], words) == 84)
            return 84;
    return 0;
}
