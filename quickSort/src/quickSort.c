/*
** quickSort.c for quickSort in /home/zero/dev/C/quickSort
**
** Made by André Paulos
** <paulos_a@epitech.net>
**
** Started on  Sat Mar 14 13:12:44 2015 André Paulos
** Last update Sat Mar 14 13:12:58 2015 André Paulos
*/

#include "quickSort.h"

void        quickSortRec(int *tab, int min, int max)
{
    int     pivotIndex;
    int     tmp_max;
    int     tmp_min;
    int     tmp;

    pivotIndex = 0;
    tmp_max = 0;
    tmp_min = 0;

    if (min < max)
    {
        pivotIndex = min;
        tmp_max = max;
        tmp_min = min;
        while (tmp_min < tmp_max)
        {
            while ((tab[tmp_min] <= tab[pivotIndex]) && ++tmp_min < max);
            while (tab[--tmp_max] > tab[pivotIndex] && tmp_max > 0);
            if (tmp_min < tmp_max)
            {
                tmp = tab[tmp_min];
                tab[tmp_min] = tab[tmp_max];
                tab[tmp_max] = tmp;
            }
        }
        tmp = tab[pivotIndex];
        tab[pivotIndex] = tab[tmp_max];
        tab[tmp_max] = tmp;
        quickSortRec(tab, min, tmp_max - 1);
        quickSortRec(tab, tmp_max + 1, max);
    }
}

void        show_tab(int *tab, int size)
{
    int     i;

    i = 0;
    for (i = 0; i < size; ++i)
        printf("%d\n", tab[i]);
}

void        quickSort(int *tab, int size)
{
    quickSortRec(tab, 0, size);
    show_tab(tab, size);
}
