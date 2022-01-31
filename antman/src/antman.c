/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** antman
*/

#include <stdlib.h>

#include "antman.h"

int antman_lyrics_file(char *file_path)
{
    int *count = NULL;
    char *text = NULL;
    char **words_arr = NULL;

    if ((text = get_file_content(file_path)) == NULL)
        return 84;
    if ((count = my_malloc(sizeof(int) * my_strlen(text), NULL)) == NULL)
        return 84;
    if ((words_arr = my_str_to_words_array(text)) == NULL)
        return 84;
    return get_and_display_compression(count, text, words_arr);
}

int antman_image_file(char *file_path)
{
    image_t *image = malloc(sizeof(image_t));

    if (image == NULL)
        return 84;
    if ((image->image = get_file_content(file_path)) == NULL)
        return 84;
    if (get_and_display_new_picture(image) == 84)
        return 84;
    free(image->image);
    free(image->to_compare);
    free(image);
    return 0;
}

int antman_base(char *file_path, int type)
{
    switch (type) {
        case 1: return antman_lyrics_file(file_path); break;
        case 2: return antman_lyrics_file(file_path); break;
        case 3: return antman_image_file(file_path); break;
    }
    return 84;
}
