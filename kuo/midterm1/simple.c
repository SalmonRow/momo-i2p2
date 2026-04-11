#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void to_hex(char *src, char *dest)
{
    dest[0] = '\0';
    char buffer[10005];
    strcpy(buffer, src);
    char *token = strtok(buffer, "|");
    while (token)
    {
        long long val = atoll(token);
        char hex[20];
        sprintf(hex, "%X", val);
        strcat(dest, hex);
        token = strtok(NULL, "|");
    }
}

int main()
{
    int q;
    char input[10005];
    char s[10005] = "";
    scanf("%s", input);
    scanf("%d", &q);
    to_hex(input, s);

    while (q--)
    {
        char cmd[10];
        scanf("%s", cmd);
        if (strcmp(cmd, "Insert") == 0)
        {
            int i;
            char str[10005], n[10005] = "";
            scanf("%d %s", &i, str);
            to_hex(str, n);

            int len_n = strlen(n);
            int len_s = strlen(s);
            if (i > len_s)
                i = len_s;

            memmove(s + i + len_n, s + i, len_s - i + 1);
            memcpy(s + i, n, len_n);
        }
        else if (strcmp(cmd, "Remove") == 0)
        {
            int j, len;
            scanf("%d %d", &j, &len);

            int len_s = strlen(s);

            if (j < len_s)
            {
                if (j + len > len_s)
                    len = len_s - j;
                memmove(s + j, s + j + len, len_s - (j + len) + 1);
            }
        }
    }

    for (int i = 0; s[i] && s[i + 1]; i += 2)
    {
        unsigned int val;
        sscanf(s + i, "%2x", &val);
        printf("%c", (char)val);
    }
    printf("\n");
    return 0;
}