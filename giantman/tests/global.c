/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** global
*/

#include "giantman.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_file_detection_success, test_file_detection_success)
{
    char file_path[] = "./Makefile";
    int result = giantman_base(file_path, 1);

    cr_assert_eq(result, 0);
}

Test(test_file_detection_fail, test_file_detection_work_fail)
{
    char file_path[] = "./do.not.exist";
    int result = giantman_base(file_path, 1);

    cr_assert_eq(result, 84);
}

Test(test_text_file_success, test_text_file_success)
{
    char file_path[] = "./Makefile";
    int result = giantman_lyrics_file(file_path);

    cr_assert_eq(result, 0);
}

Test(test_text_file_fail, test_text_file_fail)
{
    char file_path[] = "./do.not.exist";
    int result = giantman_lyrics_file(file_path);

    cr_assert_eq(result, 84);
}

Test(test_file_display_success, test_file_display_success)
{
    char file_path[] = "./Makefile";
    int result = get_and_display_new_picture(file_path);

    cr_assert_eq(result, 0);
}

Test(test_file_display_fail, test_file_display_fail)
{
    char file_path[] = "./do.not.exist";
    int result = get_and_display_new_picture(file_path);

    cr_assert_eq(result, 84);
}

Test(test_image_uncompressed_fail, test_image_uncompressed_fail)
{
    int result = uncompress_image(NULL);

    cr_assert_eq(result, 84);
}

Test(test_dictionary_detection_fail_NULL, test_dictionary_detection_fail_NULL)
{
    cr_assert_eq(get_dictionnary(NULL), NULL);
}

// tests fail
Test(test_dictionary_detection_fail, test_dictionary_detection_fail)
{
    cr_assert_eq(get_dictionnary("q"), NULL);
}

// tests fail
Test(test_dictionary_detection_success, test_dictionary_detection_success)
{
    char **test = get_dictionnary("vibrationsmight");

    cr_assert_eq(test[0], "");
    free(test);
}

// tests fail
/*Test(test_words_replacement_success, test_words_replacement_success)
{
    char file_path[] = "./Makefile";
    int result = replace_word(words, dictionnary, i)

    cr_assert_eq(result, 0);
}*/
