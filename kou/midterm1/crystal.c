#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long *h = malloc(n * sizeof(long long));
    long long *v = malloc(n * sizeof(long long));
    long long *p = calloc(n + 1, sizeof(long long));
    int *stk = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &h[i], &v[i]);
        while (top >= 0 && h[stk[top]] < h[i])
        {
            int smaller = stk[top];
            p[i + 1] += v[smaller];
            top--;
        }

        if (top >= 0)
        {
            int taller = stk[top];
            p[taller + 1] += v[i];
        }
        top++;
        stk[top] = i;
    }

    long long max = 0;
    int best = 1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > max)
        {
            max = p[i];
            best = i;
        }
    }

    printf("%d %lld\n", best, max);
    return 0;
}