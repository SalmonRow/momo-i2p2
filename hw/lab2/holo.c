#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char holo[205];
    scanf("%s", holo);

    char *plus_sign = strchr(holo, '+');
    if (plus_sign)
    {
        *plus_sign = '\0';
        char *snum1 = holo;
        char *snum2 = plus_sign + 1;

        char result[205];
        int k = 0, carry = 0;
        int i = strlen(snum1) - 1;
        int j = strlen(snum2) - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += snum1[i--] - '0';
            if (j >= 0)
                sum += snum2[j--] - '0';

            result[k++] = (sum % 10) + '0';
            carry = sum / 10;
        }
        for (int m = k - 1; m >= 0; m--)
        {
            printf("%c", result[m]);
        }
    }

    return 0;
}