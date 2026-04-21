#include <stdio.h>

void check_bit(unsigned int a)
{
    char *state = (((a >> 2) & 1) == 1) ? "ON" : "OFF";
    printf("%s\n", state);
}

void turn_on(unsigned int a)
{
    a = a | (1 << 4);
    printf("%u\n", a);
}

void force_off(unsigned int a)
{
    a = a & ~1; // due to two's complement -1 becomes 111111...110 bruh
    printf("%u\n", a);
}

void mirror(unsigned int a)
{
    a = ~a;
    printf("%u\n", a);
}

void parity_probe(unsigned int a)
{
    if ((a & 1) == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}

int main()
{
    // 1. check if 3rd bit is on
    check_bit(8);

    // 2. switch , turn on
    turn_on(7);

    // 3. force LSB to 0
    force_off(6);

    // 4. mirror
    mirror(8);

    // 5. parity even or odd
    parity_probe(9);
    return 0;
}