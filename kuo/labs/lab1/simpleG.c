#include <stdio.h>
#include <math.h>

double euclidean(int t1, int t2, int x1, int x2)
{
    double diff = pow((t1 - x1), 2) + pow((t2 - x2), 2);
    diff = sqrt(diff);
    return diff;
}

int main()
{
    int t1, t2, u1, u2, o1, o2;
    scanf("%d %d %d %d %d %d", &t1, &t2, &u1, &u2, &o1, &o2);

    double your_guess = euclidean(t1, t2, u1, u2);
    double opp_guess = euclidean(t1, t2, o1, o2);

    if (your_guess < opp_guess)
        printf("WIN\n");
    else if (your_guess > opp_guess)
        printf("LOSE\n");
    else
        printf("DRAW\n");
}