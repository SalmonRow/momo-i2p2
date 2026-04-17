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
    Node *curr = head;
    while (N > 1)
    {
        int steps = (abs(K) - 1) % N;
        for (int j = 0; j < steps; j++)
            curr = (K > 0) ? curr->next : curr->prev;

        printf("%d ", curr->id);
        int nk = curr->tolerance;
        Node *nhead = (K > 0) ? curr->next : curr->prev;

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        Node *temp = curr;
        curr = nhead;
        K = nk;
        free(temp);
        N--;
    }
    printf("\n%d\n", curr->id);
}