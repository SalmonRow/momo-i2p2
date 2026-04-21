#include <stdio.h>
#include <stdlib.h>

#define DAY_SEC (60 * 60 * 24)
#define to_sec(h, m, s) ((h * 3600) + (m * 60) + s)

char *eecs()
{
    char *s = (char *)malloc(6);
    int k;
    scanf("%d", &k);
    scanf("%s", s); // why does & s in this case don't work ?

    char *sptr = s;
    while (*sptr != '\0')
    {
        *sptr = ((*sptr - 'a' + k) % 26 + 'A');
        sptr++;
    }

    return s;
    free(s);
}
//---------------------------------------------------------------------//
void eeeeccccssss()
{
    char s[6];
    int k;
    scanf("%d %s", &k, &s);
    char *sptr = s;

    while (*sptr != '\0')
    {
        *sptr = ((*sptr - 'a' + k) % 26 + 'A');
        sptr++;
    }
    printf("%s", s);
}
//---------------------------------------------------------------------//

void tt()
{
    long h1, h2, m1, m2, s1, s2, diff, past, now;
    scanf("%ld %ld %ld", &h1, &m1, &s1);
    scanf("%ld %ld %ld", &h2, &m2, &s2);
    past = to_sec(h1, m1, s1);
    now = to_sec(h2, m2, s2);
    diff = (past - now + DAY_SEC) % DAY_SEC;

    printf("%02ld %02ld %02ld", (diff / 3600), ((diff % 3600) / 60), (diff % 60));
}
//---------------------------------------------------------------------//

void water()
{
    int l, m, n;
    scanf("%d %d %d", &l, &m, &n);
    printf("%d", ((l / m) * n));
}

//---------------------------------------------------------------------//

void scratch()
{
    long long player = 10000;
    int bankrupt = 0;
    long long a, b, p;
    while (scanf("%lld %lld %lld", &a, &b, &p) == 3)
    {
        if (bankrupt)
        {
            printf("No balance\n");
            continue;
        }

        if (a > b)
        {
            player += p;
        }
        else if (b > a)
        {
            player -= p;
            if (player <= 0)
            {
                bankrupt = 1;
                printf("0\n");
            }
        }
    }
    if (player > 0)
    {
        printf("%lld\n", player);
    }
}

//---------------------------------------------------------------------//
void sentry()
{
    int n;
    char m;
    scanf("%d %c", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                char some = ((m - 'a' + i) % 26 + 'A');
                printf("%c", some);
            }
            else
            {
                printf("?");
            }
        }
        printf("\n");
    }
}
//---------------------------------------------------------------------//
int have_seven(int num)
{
    int temp = num;
    while (temp > 0)
    {
        if (temp % 10 == 7)
        {
            return 0;
        }
        else
        {
            temp /= 10;
        }
    }
    return 1;
}

void heavy_burden()
{
    int v;
    long long treasury = 0;
    const long long lim = 100000000000000000LL;
    scanf("%d", &v);
    for (int i = 0; i < v; ++i)
    {

        long long p;
        scanf("%lld", &p);

        if ((i + 1) % 3 == 0 || have_seven((i + 1)) == 0)
        {
            treasury += p;
            if (treasury >= lim)
            {
                printf("FuLL\n");
                break;
            }
        }
    }
    printf("%lld\n", treasury);
}

//---------------------------------------------------------------------//
int main()
{

    return 0;
}