#include <stdio.h>

char **create_string_array(int n)
{
    char **string_arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        string_arr[i] = NULL;
    }
    return string_arr;
}

void append_character(char **string_arr, int *len, int idx_line, char c)
{
    int new_size = len[idx_line] + 1;
    char *temp = (char *)realloc(string_arr[idx_line], sizeof(char) * new_size);

    if (temp != NULL)
    {
        string_arr[idx_line] = temp;
        string_arr[idx_line][len[idx_line]] = c;
        len[idx_line] = new_size;
    }
}

void append_string(char **string_arr, int *len, int idx_line, char *str, int str_len)
{
    int old_size = len[idx_line];
    int new_size = len[idx_line] + str_len;
    char *temp = (char *)realloc(string_arr[idx_line], sizeof(char) * new_size);

    if (temp != NULL)
    {
        string_arr[idx_line] = temp;
        for (int ii = 0; ii < str_len; ii++)
        {
            string_arr[idx_line][old_size + ii] = str[ii];
        }
        len[idx_line] = new_size;
    }
}

void print_lines(char **string_arr, int *len, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (len[i] < 0)
        {
            for (int j = 0; j < len[i]; j++)
            {
                printf('%c', string_arr[i][j]);
            }
            printf('\n');
        }
    }
}

void delete_string_array(char **string_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(string_arr[i]);
    }
    free(string_arr);
}

/*
{
{string1}
{string 2}
{string 3}
}
*/