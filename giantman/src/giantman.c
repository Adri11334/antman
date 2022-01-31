/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** giantman
*/

#include <stdlib.h>

#include "giantman.h"

int giantman_lyrics_file(char *file_path)
{
    char replaced_words[] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    char *text = NULL;

    if ((text = get_file_content(file_path)) == NULL)
        return 84;
    for (int i = 0; i < 12; i++) {
        if (text[0] == replaced_words[i]) {
            return giantman_text_manager(text);
        } else {
            return my_putstr(text);
        }
    }
    return 0;
}

int giantman_base(char *file_path, int type)
{
    switch (type) {
        case 1: return giantman_lyrics_file(file_path); break;
        case 2: return giantman_lyrics_file(file_path); break;
        case 3: return get_and_display_new_picture(file_path); break;
    }
    return 84;
}
