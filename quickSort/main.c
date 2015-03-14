/*
** main.c for quickSort in /home/zero/dev/C/quickSort
**
** Made by André Paulos
** <paulos_a@epitech.net>
**
** Started on  Sat Mar 14 13:12:01 2015 André Paulos
** Last update Sat Mar 14 13:12:28 2015 André Paulos
*/

#include "quickSort.h"

int     main(void)
{
    int *tab;
    int i;

    tab = NULL;
    srand(time(NULL));
    tab = malloc(sizeof(int) * TAB_SIZE);
    if (!tab)
        return (EXIT_FAILURE);
    for (i = 0; i < TAB_SIZE; ++i)
    {
        tab[i] = rand() % 100;
    }
    quickSort(tab, TAB_SIZE);
    free(tab);
    return (EXIT_SUCCESS);
}
