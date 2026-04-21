#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005
#define JUMP 18

typedef struct Node
{
    int depth;
    int super[JUMP];
} Node;

Node nodes[MAXN];

void list_super(int n)
{
    for (int i = 1; i < JUMP; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nodes[j].super[i] = nodes[nodes[j].super[i - 1]].super[i - 1];
        }
    }
}

void lca(int a, int b)
{
    // swapping
    if (nodes[a].depth < nodes[b].depth)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // moving
    int diff = nodes[a].depth - nodes[b].depth;
    for (int i = 0; i < JUMP; i++)
    {
        if ((diff >> i) & 1)
            a = nodes[a].super[i];
    }

    if (a == b)
    {
        printf("%d\n", a);
        return;
    }

    for (int i = JUMP - 1; i >= 0; i--)
    {
        if (nodes[a].depth != nodes[b].depth)
        {
            a = nodes[a].super[i];
            b = nodes[b].super[i];
        }
    }

    printf("%d\n", nodes[a].super[0]);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    nodes[1].depth = 0;
    nodes[1].super[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &nodes[i].super[0]);
        nodes[i].depth = nodes[nodes[i].super[0]].depth + 1; // compute this in one line, garanteeed value before will be less than after...
    }

    list_super(n);

    while (q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        lca(a, b);
    }
    return 0;
}