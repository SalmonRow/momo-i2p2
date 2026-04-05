#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        uint32_t bob;
        scanf("%x", &bob);

        // rule one. if there is adjacent immediately
        if ((bob & (bob >> 1)) != 0)
        {
            printf("0xFFFFFFFF\n");
            continue;
        }

        // rule two, invert every sig between msb and lsb if it's not msb = 0 and lsb = 0
        int lsb = -1, msb = -1;
        for (int i = 0; i < 32; i++)
        {
            if ((bob >> i) & 1)
            {
                if (lsb == -1)
                    lsb = i;
                msb = i;
            }
        }

        if (lsb != -1 && msb != lsb)
        {
            for (int i = lsb + 1; i < msb; i++)
            {
                bob ^= (1U << i);
            }
        }

        // rule 3 sum??
        uint32_t bob0, bob1, bob2, bob3, csum;
        bob0 = (bob >> 0) & 0xFF;
        bob1 = (bob >> 8) & 0xFF;
        bob2 = (bob >> 16) & 0xFF;
        bob3 = (bob >> 24) & 0xFF;

        csum = bob0 ^ bob1 ^ bob2 ^ bob3;

        bob = (bob & 0xFFFFFF00) | csum;

        printf("0x%08X\n", bob);
    }
    return 0;
}