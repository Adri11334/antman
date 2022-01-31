/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** text_occurrence
*/

#include "antman.h"
#include <stdlib.h>
#include <stdbool.h>

int is_unique(char *word, char **unique, int *uniq_nb, int *j)
{
    bool is_unique = true;

    if (my_strlen(word) < 2)
        return -84;
    for ((*j) = 1; (*j) < (*uniq_nb) && is_unique; (*j)++)
        if (my_strcmp(unique[(*j)], word) == 0)
            is_unique = false;
    if (is_unique) {
        free(unique[(*uniq_nb)]);
        if ((unique[(*uniq_nb)] = my_malloc(sizeof(char) *
        my_strlen(word) + 1, word)) == NULL)
            return 84;
        return 1;
    } else
        return 2;
    return 0;
}

int detect_unique_words(char **ws_arr, int *uniq_nb, \
int *count, char **unique_words)
{
    int j = 0;

    for (int i = 0; ws_arr[i] != NULL; i++) {
        switch (is_unique(ws_arr[i], unique_words, uniq_nb, &j)) {
            case 1: count[(*uniq_nb)]++; (*uniq_nb)++; break;
            case 2: count[j - 1]++; break;
            case 84: return 84;
        }
    }
    return 0;
}

char **get_unique_words(char **ws_arr, int *uniq_nb, int *count, int txt_l)
{
    char **unique_words = my_malloc(sizeof(char *) * txt_l, NULL);

    if (unique_words == NULL)
        return NULL;
    for (int i = 0; i < txt_l; i++) {
        if ((unique_words[i] = my_malloc(sizeof(char) * 2, NULL)) == NULL)
            return NULL;
        count[i] = 0;
    }
    if ((unique_words[(*uniq_nb)] = my_malloc(sizeof(char) * 2, NULL)) == NULL)
        return NULL;
    (*uniq_nb)++;
    if (detect_unique_words(ws_arr, uniq_nb, count, unique_words) == 84)
        return NULL;
    return unique_words;
}
