#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int a, b, c;
        scanf("%d %d", &a, &b);

        if (b % a == 0)
        {
            printf("%d\n", a);
            continue;
        }
        else if (a % b == 0)
        {
            printf("%d\n", b);
            continue;
        }

        c = (a < b) ? a : b;
        while (c > 1)
        {
            c--;
            if (b % c == 0 && a % c == 0)
            {
                printf("%d\n", c);
                break;
            }
        }
    }
    return 0;
}