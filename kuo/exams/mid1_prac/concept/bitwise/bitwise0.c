#include <stdio.h>

// foundation level
void l_shifts(unsigned int a)
{
    unsigned int b, c;
    b = (a << 1);
    c = (a << 2);

    printf("Here are the Left Shifts\nBy 1 : %d\nBy 2 : %d\n", b, c);
}

void r_shifts(unsigned int a)
{
    unsigned int b, c;
    b = (a >> 1);
    c = (a >> 2);

    printf("Here are the Right Shifts\nBy 1 : %d\nBy 2 : %d\n", b, c);
}

void check_bit(unsigned int x, int bb)
{
    int b = (x >> bb) & 1;
    char *result = (b == 0) ? "off" : "on";
    printf("the result for <%d> bit of number %d is : %s\n", bb, x, result);
}

//----------------------------------------------
// void create_mask()
// {
//     //three ways
//     //1. single point -> target one bit at index n
//     int
// }
int main()
{
    int t;
    scanf("%d", &t);
    if (t == 1)
    {

        for (unsigned int i = 8; i <= 12; i++)
        {
            printf("Shifting for [%d]\n", i);
            l_shifts(i);
            printf("-------------\n");
            r_shifts(i);
            printf("-------------\n");
        }
    }
    else if (t == 2)
    {
        int j = 11; // 1011
        check_bit(j, 3);
        check_bit(j, 2);
        check_bit(j, 1);
        check_bit(j, 0);
    }
    return 0;
}

/*

0001

x >> 4

*/