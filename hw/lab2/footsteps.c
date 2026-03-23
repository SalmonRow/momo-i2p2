#include <stdio.h>
#include <stdlib.h>

int **create_walkway(int n, const int *len)
{
    int **tile = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        tile[i] = (int *)malloc(len[i] * sizeof(int));
    }
    return tile;
}

void activate_walkway(int n, const int *len, int **tile)
{
    for (int i = 0; i < n; i++)
    {
        int *og = (int *)malloc(len[i] * sizeof(int));
        for (int j = 0; j < len[i]; j++)
        {
            og[j] = tile[i][j];
        }

        for (int j = 0; j < len[i]; j++)
        {
            tile[i][j] = og[j];
            if (j - 1 >= 0)
                tile[i][j] += og[j - 1];
            if (j + 1 < len[i])
                tile[i][j] += og[j + 1];
        }
        free(og);
    }
}

void delete_walkway(int n, int **tile)
{
    for (int i = 0; i < n; i++)
    {
        free(tile[i]);
    }
    free(tile);
}