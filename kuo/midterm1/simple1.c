#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10005

void to_hex(char *source, char *dest)
{
    dest[0] = '\0';
    char buffer[MAXN];
    strcpy(buffer, source);
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
    char input[MAXN];
    char str[MAXN] = "";
    scanf("%s", input);
    scanf("%d", &q);
    to_hex(input, str);

    while (q--)
    {
        char cmd[20];
        scanf("%s", cmd);
        if (strcmp(cmd, "Insert"))
        {
            int i;
            char new_input[MAXN], new_str[MAXN] = "";
            scanf("%d %s", &i, new_input);
            to_hex(new_input, new_str);

            int len_str = strlen(str);
            int len_nstr = strlen(new_str);

            memmove(str + i + len_nstr, str + i, len_str - i + 1);
            memcpy(str + i, new_str, len_nstr);
        }

        else if (strcmp(cmd, "Remove"))
        {
            int i, rlen;
            scanf("%d %d", &i, &rlen);

            int len_str = strlen(str);

            memmove(str + i, str + i + rlen, len_str - (i + rlen) + 1);
        }
    }

    for (int i = 0; str[i] && str[i + 1]; i += 2)
    {
        unsigned int val;
        sscanf(str + i, "%2x", &val);
        printf("%c", (char)val);
    }
    printf("\n");
    return 0;
}