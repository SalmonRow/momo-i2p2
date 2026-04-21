#include <stdio.h>

void print_binary(unsigned int a)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
}

void change_bottom_bit(unsigned int a, int bnum)
{
    printf("This is the initial-binary of the inputted number\n");
    printf("[%d]\n", a);
    print_binary(a);
    printf("After shifting\n");
    a = (a >> bnum);
    a = (a << bnum);
    printf("[%d]\n", a);
    print_binary(a);
}

void change_btm_four(unsigned int a)
{
    printf("OG : ");
    print_binary(a);
    a = a & ~0xF;
    print_binary(a);
}

void check_ptwo(unsigned int a)
{
    if (((a > 0) && (a & (a - 1)) == 0))
    {
        printf("%u is a power of two\n", a);
    }
    else
    {
        printf("no\n");
    }
}

unsigned char extract(unsigned int a, int nth_byte)
{
    a = (a >> (8 * (nth_byte - 1))) & 0xFF;
    return a;
}

unsigned int create_mask(int i, int j)
{
    int range = j - i;
    unsigned int mask = ((1 << range) - 1) << i;
    printf("Mask from %d to %d: 0x%X\n", i, j, mask);
    return mask;
}

void check_adj(unsigned int a)
{
    a = (a & (a >> 1));
    if (a == 0)
        printf("There is NO one next to each other !\n");
    else
        printf("There IS a one next to each other !!\n");
}

int main()
{

    // 1. changing all the lower n bits to 0
    change_bottom_bit(222, 4);
    printf("-------------\n");
    change_btm_four(222);

    // 2.power of two check
    printf("*************************\n");
    check_ptwo(16); // yes
    check_ptwo(9);  // no

    // 3.extract the second byte ??
    printf("*************************\n");
    unsigned int og = 0x12345678;
    int nth_byte = 3;
    unsigned char result = extract(og, nth_byte);
    printf("OG: 0x%X\n", og);
    printf("New: 0x%X\n", result);

    // 4. mask generator
    printf("*************************\n");
    create_mask(2, 6);
    create_mask(2, 10);

    // 5. adjasent
    printf("*************************\n");
    check_adj(55);
    check_adj(7); // 0111
    check_adj(8); // 1000
    return 0;
}

/*

0000
0010
0100
0110
1000
1010
1100
1110


7 & 6
111
110
110


6 & 6
110
110
110

*/