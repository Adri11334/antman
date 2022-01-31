/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** get_words
*/

#include "antman.h"
#include <stdlib.h>

void set_new_element(int *elements, int *elements_set, int new, int to_change)
{
    elements_set[to_change] += 1;

    for (int i = 11; i > to_change; i--) {
        elements[i] = elements[i - 1];
    }
    elements[to_change] = new;
}

int elements_cmp(char **words, int arr[], int *elements, int i)
{
    for (int j = 0; j < 11; j++)
        if ((my_strlen(words[i]) * arr[i])
        > (my_strlen(words[elements[j]]) * arr[elements[j]])
        && my_strcmp(words[i], words[elements[j]]) != 0)
            return j;
    return -1;
}

int set_new_words(int elements_set[], char **edit_words, char **words, \
int elements[])
{
    int word_set = 0;

    for (int i = 0; i < 11; i++)
        if (elements_set[i] > 0) {
            edit_words[word_set] = my_malloc(my_strlen(words[elements[i]]) + 1,
            words[elements[i]]);
            word_set++;
        }
    return 0;
}

char **get_biggests(int arr[], char **words, int length)
{
    char **edit_words = my_malloc(sizeof(char *) * 12, NULL);
    int elements[11] = {0};
    int elements_set[11] = {0};
    int to_change = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] < 2)
            continue;
        to_change = elements_cmp(words, arr, elements, i);
        if (to_change != -1)
            set_new_element(elements, elements_set, i, to_change);
    }
    set_new_words(elements_set, edit_words, words, elements);
    return edit_words;
}
