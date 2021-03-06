/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** restart
*/

////////////////////////////////////////////////////////////
//
// Get back to the first position of the linked list
//
// @param data the pointeur to the data we need to push
////////////////////////////////////////////////////////////

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Get back to the first pos of a linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
int back_to_start(linked_list **node)
{
    if ((*node) == NULL)
        return 84;
    while ((*node)->prev != NULL)
        *node = (*node)->prev;
    return 0;
}
