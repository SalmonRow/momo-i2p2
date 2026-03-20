#include <stdio.h>

int main()
{
    long long pocket = 10000;
    long long a, b, c;
    int alive = 1;
    while (scanf("%lld %lld %lld", &a, &b, &c) == 3)
    {
        if (!alive)
        {
            printf("No balance\n");
            continue;
        }

        if (a > b)
        {
            pocket += c;
        }
        else if (a < b)
        {
            pocket -= c;
            if (pocket <= 0)
            {
                printf("0\n");
                alive = 0;
            }
        }
    }
    if (pocket > 0)
    {
        printf("%lld\n", pocket);
    }
    return 0;
}