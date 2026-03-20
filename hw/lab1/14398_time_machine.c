#include <stdio.h>
#define DAY_SEC (60 * 60 * 24)
#define to_sec(h, m, s) ((h * 3600) + (m * 60) + s)

int main()
{
    int h1, m1, s1, h2, m2, s2;
    if (scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2) != 6)
        return 0;
    long present = to_sec(h1, m1, s1);
    long from = to_sec(h2, m2, s2);

    long diff = (present - from + DAY_SEC) % DAY_SEC;

    printf("%02ld %02ld %02ld", (diff / 3600), ((diff % 3600) / 60), diff % 60);

    return 0;
}