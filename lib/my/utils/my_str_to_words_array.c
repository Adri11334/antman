/*
** EPITECH PROJECT, 2022
** lib
** File description:
** str_word_array from stumper 01
*/

#include <stdlib.h>
#include "../my.h"

int check_new_word(char *str, char **words, int i, int *word_i)
{
    int individual_word = 0;

    if (((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
    || ((str[i - 1] != NULL && (str[i - 1] < 'a' || str[i - 1] > 'z')
    && (str[i - 1] < 'A' || str[i - 1] > 'Z')))) {
        (*word_i)++;
        words[*word_i] = my_malloc(my_strlen(str) + 1, NULL);
        if (words[*word_i] == NULL)
            return 84;
        return 1;
    }
    return 0;
}

char **my_str_to_words_array(char *str)
{
    char **words = my_malloc(sizeof(char*) * (my_strlen(str) + 1), NULL);
    int words_index = 0;
    int words_letter = 0;

    if (!words)
        return NULL;
    words[words_index] = my_malloc(my_strlen(str) + 1, NULL);
    if (words[words_index] == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        switch (check_new_word(str, words, i, &words_index)) {
            case 1: words_letter = 0; break;
            case 2: words_letter = 0; continue; break;
            case 84: return NULL; break;
        }
        words[words_index][words_letter] = str[i];
        words_letter++;
    }
    return words;
}
