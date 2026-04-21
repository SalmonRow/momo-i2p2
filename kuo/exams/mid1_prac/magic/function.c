#include "function.h"

// typedef struct Mage
// {
//     char name[30];
//     int value;
// } Mage;

// 1. Ascending
// helper func
int is_prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int cmp_ascending(const void *a, const void *b)
{
    Mage *m1 = (Mage *)a;
    Mage *m2 = (Mage *)b;

    int diff = m1->value - m2->value;

    if (diff != 0)
        return diff;

    return strcmp(m1->name, m2->name);
}

// 2. Square Ascending
int cmp_square_ascending(const void *a, const void *b)
{
    Mage *m1 = (Mage *)a;
    Mage *m2 = (Mage *)b;

    int diff = ((m1->value) * (m1->value)) - ((m2->value) * (m2->value));

    if (diff != 0)
        return diff;

    return strcmp(m1->name, m2->name);
}

// 3. Digit Sum Ascending
int cmp_digit_sum_ascending(const void *a, const void *b)
{
    Mage *m1 = (Mage *)a;
    Mage *m2 = (Mage *)b;

    int v1, v2, diff;
    v1 = (abs(m1->value) / 10) + (abs(m1->value) % 10);
    v2 = (abs(m2->value) / 10) + (abs(m2->value) % 10);
    diff = v1 - v2;
    if (diff != 0)
        return diff;

    return strcmp(m1->name, m2->name);
}

// 4. Swapped Digit Ascending
int cmp_swapped_digit_ascending(const void *a, const void *b)
{
    Mage *m1 = (Mage *)a;
    Mage *m2 = (Mage *)b;

    int v1, v2, diff;
    v1 = ((m1->value < 0) ? -1 : 1) * ((abs(m1->value) / 10) + (abs(m1->value) % 10) * 10);
    v2 = ((m2->value < 0) ? -1 : 1) * ((abs(m2->value) / 10) + (abs(m2->value) % 10) * 10);
    diff = v1 - v2;

    if (diff != 0)
        return diff;

    return strcmp(m1->name, m2->name);
}

// 5. Prime First Ascending
int cmp_prime_first_ascending(const void *a, const void *b)
{
    Mage *m1 = (Mage *)a;
    Mage *m2 = (Mage *)b;

    int v1, v2, diff;
    v1 = is_prime(abs(m1->value));
    v2 = is_prime(abs(m2->value));
    diff = v2 - v1;

    if (v1 != v2)
        return diff;
    if (m1->value != m2->value)
        return m1->value - m2->value;

    return strcmp(m1->name, m2->name);
}

// Use qsort with the corresponding function according to the rule.
void solve(Mage *mages, int n, int rule)
{
    if (rule == 0)
    {
        qsort(mages, n, sizeof(mages[0]), cmp_ascending);
    }
    else if (rule == 1)
    {
        qsort(mages, n, sizeof(mages[0]), cmp_square_ascending);
    }
    else if (rule == 2)
    {
        qsort(mages, n, sizeof(mages[0]), cmp_digit_sum_ascending);
    }
    else if (rule == 3)
    {
        qsort(mages, n, sizeof(mages[0]), cmp_swapped_digit_ascending);
    }
    else if (rule == 4)
    {
        qsort(mages, n, sizeof(mages[0]), cmp_prime_first_ascending);
    }
}
