#include <stdio.h>
// Euclidean tiling they said...

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int a, b, c;
        scanf("%d %d", &a, &b);

        while (b)
        {
            a %= b;

            c = a, a = b, b = c;
        }
        printf("%d\n", a);
    }

    return 0;
}