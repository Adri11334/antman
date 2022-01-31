/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_
    #include "my.h"

    typedef struct image_s {
        char *image;
        char *current;
        int current_times;
        int current_value;
    } image_t;

    int giantman_base(char *file_path, int type);
    int giantman_text_manager(char *text);
    int giantman_lyrics_file(char *file_path);
    int uncompress_image(image_t *image);
    int replace_word(char **words, char **dictionnary, int i);
    char **get_dictionnary(char *text);

    int replacing_char_by_words(char **words, char **dictionnary);

    int get_and_display_new_picture(char *file_path);

#endif /* !GIANTMAN_H_ */
