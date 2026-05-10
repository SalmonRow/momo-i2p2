#include "function.h"

Node *detectCycle(Node *head)
{
    Node *s = head, *f = head;
    while (f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;

        if (f == s)
        {
            s = head;
            while (s != f)
            {
                s = s->next;
                f = f->next;
            }
            return s;
        }
    }

    if (f->next)
        return f->next;
    else
        return f;
}