/*
** EPITECH PROJECT, 2022
** antman
** File description:
** p_manager
*/

#include <stdlib.h>

#include "antman.h"

char *next_line(int *i, char *str)
{
    char *new_str = NULL;
    int line_length = 0;
    int str_index = 0;

    for (int t_i = *i; str[t_i] != '\n' && str[t_i] != '\0'; t_i++)
        line_length++;
    if ((new_str = my_malloc(line_length + 1, NULL)) == NULL)
        return NULL;
    while (line_length > 0) {
        new_str[str_index] = str[*i];
        str_index++;
        (*i)++;
        line_length--;
    }
    if (str[*i] == '\n')
        (*i)++;
    return new_str;
}

int compress_last_lines(int *occurrence, image_t *image, int end)
{
    if (end == 1) {
        if ((*occurrence) == 0) {
            free(image->to_compare);
            if ((image->to_compare = my_malloc(my_strlen(image->current) + 1,
            image->current)) == NULL)
                return 84;
        }
        if ((*occurrence) > 1)
            my_printf("%d%c", (*occurrence), 15);
        my_printf("%s\n", image->to_compare);
        return -5;
    }
    return 0;
}

int start_compress_new(image_t *image, int *occurrence)
{
    free(image->to_compare);
    if ((image->to_compare = my_malloc(my_strlen(image->current) + 1,
    image->current)) == NULL)
        return 84;
    free(image->current);
    (*occurrence)++;
    return 0;
}

int compress_image(int *occurrence, image_t *image, int end)
{
    if ((*occurrence) == 0) {
        if (start_compress_new(image, occurrence) == 84)
            return 84;
        if (end == 0)
            return 1;
    } else if (my_strcmp(image->to_compare, image->current) == 0) {
        (*occurrence)++;
        free(image->current);
        if (end == 0)
            return 1;
    } else {
        if ((*occurrence) > 1)
            my_printf("%d%c", (*occurrence), 15);
        my_printf("%s\n", image->to_compare);
        (*occurrence) = 0;
        if (end == 0)
            return 2;
    }
    return compress_last_lines(occurrence, image, end);
}

int get_and_display_new_picture(image_t *image)
{
    int occurrence = 0;
    int index = 0;

    if ((image->current = next_line(&index, image->image)) == NULL)
        return 84;
    while (image->image[index] != '\0') {
        switch (compress_image(&occurrence, image, 0)) {
            case 1: if ((image->current = next_line(&index,
                    image->image)) == NULL) { return 84; }; break;
            case 2: break;
            case 84: return 84;
        }
        if (image->image[index] == '\0')
            compress_image(&occurrence, image, 1);
    }
    return 0;
}
