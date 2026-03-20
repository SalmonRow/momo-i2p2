#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d", &n);
    int cortisols[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cortisols[i]);
    }
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int stress = 0;
        while (a <= b)
        {
            stress += cortisols[a];
            a++;
        }
        printf("%d\n", stress);
    }
    return 0;
}