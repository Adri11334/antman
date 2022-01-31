/*
** EPITECH PROJECT, 2022
** antman
** File description:
** global
*/

#include "antman.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_file_detection_work, test_file_detection_work)
{
    char file_path[] = "./Makefile";
    int result = antman_base(file_path, 1);

    cr_assert_eq(result, 0);
}

Test(test_text_file_work, test_text_file_work)
{
    char file_path[] = "./Makefile";
    int result = antman_lyrics_file(file_path);

    cr_assert_eq(result, 0);
}

Test(test_text_file_dont_work, test_text_file_dont_work)
{
    char file_path[] = "./none.yes";
    int result = antman_lyrics_file(file_path);

    cr_assert_eq(result, 84);
}

Test(test_picture_detection_work, test_picture_detection_work)
{
    char file_path[] = "../bonus/comp_test/TA/tl.ppm";
    int result = antman_base(file_path, 3);

    cr_assert_eq(result, 0);
}

Test(test_picture_file_work, test_picture_file_work)
{
    char file_path[] = "../bonus/comp_test/TA/tl.ppm";
    int result = antman_image_file(file_path);

    cr_assert_eq(result, 0);
}

Test(test_picture_file_dont_work, test_picture_file_dont_work)
{
    char file_path[] = "./none.yes";
    int result = antman_image_file(file_path);

    cr_assert_eq(result, 84);
}
