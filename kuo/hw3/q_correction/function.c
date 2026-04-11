#include "function.h"
// typedef struct Node
// {
//     const int v;
//     struct Node *next;
// } Node;

void solve(Node *head, int l, int r)
{
    if (!head || l == r)
        return;

    Node *prev = head;
    for (int i = 0; i < l - 1; i++)
    {
        prev = prev->next;
    }

    Node *cur = prev->next;

    for (int i = 0; i < r - l; i++)
    {
        Node *temp = cur->next;
        cur->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
}
