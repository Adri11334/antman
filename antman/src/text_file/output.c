/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** output
*/

#include <fcntl.h>
#include <stddef.h>

#include "antman.h"

int show_compressed_file(char **text, char **replaced_words)
{
    char replace_words[] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    int display_cmp = 0;

    while (replaced_words[display_cmp] != NULL) {
        my_putchar(replace_words[display_cmp]);
        my_putstr(replaced_words[display_cmp]);
        display_cmp++;
    }
    if (display_cmp > 0)
        my_putchar('\n');
    for (int i = 0; text[i] != NULL; i++) {
        if (text[i + 1] != NULL && (text[i + 1][0] > 15 && text[i + 1][0] < 27)
        && (text[i][0] < 16 || text[i][0] > 26) && text[i][0] == ' ')
            continue;
        my_putstr(text[i]);
    }
    free_double_char(text);
    free_double_char(replaced_words);
    return 0;
}
