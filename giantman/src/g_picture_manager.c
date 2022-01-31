/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** g_picture_manager
*/

#include <stdlib.h>

#include "giantman.h"

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

int str_contain(char *str, char c)
{
    int founded = 0;

    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            founded++;
    return founded;
}

int show_color(int occurrence, char *color)
{
    if (color == NULL)
        return 84;
    for (int i = 0; i < occurrence; i++)
        my_printf("%s\n", color);
    return 0;
}

int uncompress_image(image_t *image)
{
    char *color = NULL;
    int occurrence_i_end = 0;

    if (image == NULL)
        return 84;
    if (str_contain(image->current, 15) == 0) {
        my_printf("%s\n", image->current);
        return 0;
    }
    for (int i = 0; occurrence_i_end == 0; i++)
        if (image->current[i] == 15)
            occurrence_i_end = i + 1;
    image->current[occurrence_i_end - 1] = ' ';
    if ((color = my_malloc(my_strlen(image->current), NULL)) == NULL)
        return 84;
    for (int i = 0; image->current[occurrence_i_end] != 0; i++) {
        color[i] = image->current[occurrence_i_end];
        occurrence_i_end++;
    }
    return show_color(my_getnbr(image->current), color);
}

int get_and_display_new_picture(char *file_path)
{
    image_t *image = malloc(sizeof(image_t));
    int index = 0;

    if (image == NULL)
        return 84;
    if ((image->image = get_file_content(file_path)) == NULL)
        return 84;
    while (image->image[index] != '\0') {
        if ((image->current = next_line(&index, image->image)) == NULL)
            return 84;
        if (uncompress_image(image) == 84)
            return 84;
        free(image->current);
    }
    free(image->image);
    free(image);
    return 0;
}
