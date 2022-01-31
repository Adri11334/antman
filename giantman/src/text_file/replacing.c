/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** replacing
*/

#include <stdlib.h>

#include "giantman.h"

int should_i_put_a_space(int i, char *string)
{
    if (i != 1 && string[0] != '\n')
        my_putchar(' ');
    return 0;
}

int replace_word(char **words, char **dictionnary, int i)
{
    int word_founded = 0;

    for (int j = 1; dictionnary[j] != NULL && j < 26; j += 2) {
        if (dictionnary[j] == NULL)
            continue;
        if (words[i][0] == dictionnary[j][0] && word_founded == 0) {
            should_i_put_a_space(i, words[i - 1]);
            my_putstr(dictionnary[j + 1]);
            words[i][0] = '\0';
            return 1;
            continue;
        }
    }
    return 0;
}

int replacing_char_by_words(char **words, char **dictionnary)
{
    if (words == NULL || dictionnary == NULL)
        return 84;
    for (int i = 0; words[i] != NULL; i++) {
        replace_word(words, dictionnary, i);
        my_putstr(words[i]);
    }
    return 0;
}
