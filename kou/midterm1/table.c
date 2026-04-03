#include <stdio.h>
#include <stdint.h>

void solve()
{
    uint32_t n;
    scanf("%x", &n);
    if (n & (n << 1))
    {
        printf("0xFFFFFFFF\n");
        return;
    }
    if (n)
    {
        int msb = 31 - __builtin_clz(n), lsb = __builtin_ctz(n);
        if (msb > lsb + 1)
        {
            uint32_t mask = ((1U << (msb - lsb - 1)) - 1) << (lsb + 1);
            n ^= mask;
        }
    }
    uint8_t ck = (n >> 24) ^ (n >> 16) ^ (n >> 8) ^ (n & 0xFF);
    printf("0x%08X\n", (n & 0xFFFFFF00) | ck);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}