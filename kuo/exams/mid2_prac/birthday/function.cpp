#include "function.h"
#include <iostream>
using namespace std;

KuoYangPresent::KuoYangPresent(int k)
{
    this->k = k;
    sz = 0;
    head = nullptr;
    mid = nullptr;
    tail = nullptr;

    now = 0;
    reverse = false;
}
void KuoYangPresent::Push(int x)
{
    Node *nn = new Node();
    nn->val = x;
    nn->tag = now;
    nn->prev = nullptr;
    nn->next = nullptr;

    sz++;
    if (sz == 1)
    {
        head = nn;
        mid = nn;
        tail = nn;
        return;
    }

    if (reverse) // so that there would not be a O(n) for reversing the ll later
    {
        head->prev = nn;
        nn->next = head;
        head = nn;

        if (sz % 2 == 1)
        {
            mid = mid->prev;
        }
    }
    else
    {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;

        if (sz % 2 == 1)
        {
            mid = mid->next;
        }
    }
}
void KuoYangPresent::Pop()
{
    Node *target = mid;

    if (reverse) // prevent o(n) in reverse later
        mid = target->next;
    else
        mid = target->prev;

    if (sz == 1)
    {
        head = nullptr;
        mid = nullptr;
        tail = nullptr;
    }
    else
    {
        if (target->prev != nullptr)
        {
            target->prev->next = target->next;
        }
        else
        {
            head = target->next;
        }

        if (target->next != nullptr)
        {
            target->next->prev = target->prev;
        }
        else
        {
            tail = target->prev;
        }
    }

    delete target;
    sz--;
}
void KuoYangPresent::Reverse()
{
    reverse = !reverse;

    if (sz > 0 && sz % 2 == 0)
    {
        if (reverse)
        {
            mid = mid->next;
        }
        else
        {
            mid = mid->prev;
        }
    }
}
void KuoYangPresent::ProgrammingTanoshi()
{
    now++;
}
void KuoYangPresent::KuoYangTeTe()
{
    // ...
}
void KuoYangPresent::PrintList()
{
    Node *curr = reverse ? tail : head;

    while (curr != nullptr)
    {
        if (curr->tag < now)
        {
            cout << (curr->val % k) << " ";
        }
        else
        {
            cout << curr->val << " ";
        }

        curr = reverse ? curr->prev : curr->next;
    }
    cout << endl;
}
