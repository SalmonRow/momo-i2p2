#include "function.h"

using namespace std;

List_stack::List_stack()
{
    head = NULL;
    tail = NULL;
}
List_stack::~List_stack()
{
    while (tail)
    {
        pop();
    }
}
void List_stack::push(const int &info)
{
    ListNode *newnode = new ListNode(info);

    if (head == NULL && tail == NULL) // the first elements;
    {
        head = newnode;
        tail = newnode;
    }

    tail->nextPtr = newnode;
    newnode->prevPtr = tail;
    tail = newnode; // move the tail up
}
void List_stack::pop()
{
    if (!tail)
        return;

    ListNode *delnode = tail;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prevPtr;
        tail->nextPtr = NULL;
        delnode->prevPtr = NULL;
    }
    delete delnode;
}
void List_stack::print()
{
    ListNode *cur = tail;
    while (cur)
    {
        cout << cur->data;
        if (cur->prevPtr != NULL)
            cout << " ";

        cur = cur->prevPtr;
    }
}