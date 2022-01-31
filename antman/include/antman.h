/*
** EPITECH PROJECT, 2022
** bs_antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_
    #include "my.h"

    typedef struct image_s {
        char *image;
        char *current;
        char *to_compare;
    } image_t;

    int antman_base(char *file_path, int type);
    int antman_lyrics_file(char *filepath);
    int antman_image_file(char *file_path);

    int get_and_display_compression(int *count, char *text, char **words_arr);

    char *get_file(char const *filepath);

    int free_double_char(char **arr);
    char **get_biggests(int arr[], char **words, int length);

    int show_compressed_file(char **text, char **replaced_words);
    int replace_word_by_char(char *original, char new);
    int replace_words(char new_word, char *original_word, char **words);
    int replace_uniques(char **words, char **words_to_replace);
    char **get_unique_words(char **wa, int *uniq_nb, int *c, int tl);

    char **get_pixel_array(char *str);
    int get_and_display_new_picture(image_t *image);
#endif /* !ANTMAN_H_ */
