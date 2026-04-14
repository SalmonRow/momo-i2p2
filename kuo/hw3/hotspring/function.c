#include "function.h"

// typedef struct _Node
// {
//     int id, tolerance;
//     struct _Node *next, *prev;
// } Node;

Node *createList(int n) // a butt moving func to create ll
{
    Node *head = NULL, *butt = NULL;
    for (int i = 1; i <= n; i++)
    {
        Node *nn = (Node *)malloc(sizeof(Node));
        scanf("%d", &nn->tolerance);
        nn->id = i;

        if (i == 1)
            head = nn;
        else
        {
            butt->next = nn;
            nn->prev = butt;
        }
        butt = nn;
    }
    butt->next = head;
    head->prev = butt;

    return head;
}

void solve(Node *head, int N, int K)
{
    Node *current = head;
    int n = N;
    int k = K;
    while (n > 1)
    {
        int steps = (abs(k) - 1) % n;
        for (int i = 0; i < n - 1; i++)
        {
            int stop = (abs(k) - i) % (n - 1)
        }
    }
}