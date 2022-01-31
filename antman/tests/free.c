/*
** EPITECH PROJECT, 2022
** antman
** File description:
** free
*/

#include "antman.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_free_null, test_free_null)
{
    char **arr = NULL;

    cr_assert_eq(free_double_char(arr), -1);
}

Test(test_free_filled, test_free_filled)
{
    char **arr = malloc(sizeof(char *) * 2);
    arr[0] = my_malloc(23, NULL);
    arr[1] = my_malloc(2, NULL);

    cr_assert_eq(free_double_char(arr), 0);
}
