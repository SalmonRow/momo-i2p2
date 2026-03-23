#include <stdio.h>
#include <stdlib.h>

unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k)
{
    unsigned ***arr = (unsigned ***)malloc(n * sizeof(unsigned **));
    unsigned **sub_arr = (unsigned **)malloc(n * m * sizeof(unsigned *));
    unsigned *sub_sub_arr = (unsigned *)malloc(n * m * k * sizeof(unsigned));

    for (unsigned i = 0; i < n; i++)
    {
        arr[i] = sub_arr + (i * m);
        for (unsigned j = 0; j < m; j++)
        {
            arr[i][j] = sub_sub_arr + (i * m + j) * k;
        }
    }
    return arr;
}

void delete_3d_array(unsigned ***arr)
{
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}