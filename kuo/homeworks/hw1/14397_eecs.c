#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    char *s = (char *)malloc(6 * sizeof(char));
    scanf("%d", &k);
    scanf("%5s", s);
    char *sptr = s;

    while (*sptr != '\0')
    {
        *sptr = ((*sptr - 'a' + k) % 26 + 'A');
        sptr++;
    }

    printf("%s", s);
    free(s);
    return 0;
}