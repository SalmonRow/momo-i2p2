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
    for (int i = 1; i < l; i++)
    {
        prev = prev->next;
    }

    Node *current = prev->next;
    for (int i = 1; i < r; i++)
    {
        Node *temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
}
