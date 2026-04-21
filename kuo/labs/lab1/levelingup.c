#include <stdio.h>
int plvl = 0;

int main()
{
    int actions, type;
    scanf("%d", &actions);
    int xp = 0;

    while (actions--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            xp += 10;
        }
        else if (type == 2)
        {
            xp += 15;
        }
        else if (type == 3)
        {
            xp += 100;
        }
    }

    while (xp >= ((plvl + 1) * (plvl + 1)))
    {
        int target = (plvl + 1) * (plvl + 1);
        xp -= target;
        plvl += 1;
    }

    printf("%d\n", plvl);

    return 0;
}