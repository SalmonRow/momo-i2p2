#include "function.h"

ListNode *solve(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *s = head, *f = head;
    while (f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }

    ListNode *pre = nullptr, *cur = s->next;
    s->next = nullptr;
    while (cur)
    {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    ListNode *p1 = head, *p2 = pre;
    while (p2)
    {
        ListNode *n1 = p1->next, *n2 = p2->next;
        p1->next = p2;
        p2->next = n1;
        p1 = n1;
        p2 = n2;
    }
    return head;
}