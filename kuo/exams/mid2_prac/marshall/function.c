#include "function.h"
#include <stdlib.h>

// locating platforms
Node *car_locator[100005] = {NULL};
// 1. ENTER p c
void enter(int p, int c)
{
    Node *nn = malloc(sizeof(Node));
    nn->id = c;
    nn->prev = NULL;
    nn->next = NULL;

    car_locator[c] = nn;

    if (tails[p] == NULL)
    {
        heads[p] = nn;
        tails[p] = nn;
    }
    else
    {
        tails[p]->next = nn;
        nn->prev = tails[p];
        tails[p] = nn;
    }
}

// 2. MERGE p_src p_dest
void merge(int p_src, int p_dest)
{
    if (tails[p_src] == NULL)
        return;

    if (heads[p_dest] == NULL)
    {
        heads[p_dest] = heads[p_src];
        tails[p_dest] = tails[p_src];
    }
    else
    {
        heads[p_src]->prev = tails[p_dest];
        tails[p_dest]->next = heads[p_src];

        tails[p_dest] = tails[p_src];
    }
    // empty out them
    heads[p_src] = NULL;
    tails[p_src] = NULL;
}

// 3. SPLIT p_src c p_dest
void split(int p_src, int c, int p_dest)
{
    Node *node = car_locator[c];

    // if it's the first car
    if (node == heads[p_src])
    {
        // just move to p dest without cutting
        heads[p_dest] = heads[p_src];
        heads[p_src] = NULL;
        tails[p_dest] = tails[p_src];
        tails[p_src] = NULL;
    }

    else
    {
        heads[p_dest] = node;
        tails[p_dest] = tails[p_src];
        tails[p_src] = node->prev;
        tails[p_src]->next = NULL;
        node->prev = NULL;
    }
}

// 4. REVERSE p
void reverse(int p)
{
    if (heads[p] == NULL || heads[p]->next == NULL)
    {
        return;
    }

    Node *curr = heads[p];
    Node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        curr = curr->prev;
    }

    temp = heads[p];
    heads[p] = tails[p];
    tails[p] = temp;
}

// 5. CHECK p c k
int check(int p, int c, int k)
{
    Node *curr = car_locator[c];
    while (k--)
    {
        if (curr->prev == NULL)
        {
            return curr->id;
        }
        curr = curr->prev;
    }
    return curr->id;
}