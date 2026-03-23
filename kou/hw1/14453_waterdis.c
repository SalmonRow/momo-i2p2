#include <stdio.h>

int main()
{
    int l, m, n, ans;
    scanf("%d %d %d", &l, &m, &n);
    ans = (l / m) * n;
    printf("%d", ans);

    return 0;
}