#include "function.h"

using namespace std;

List_stack::List_stack() // initiate a husk/ shell
{
    head = NULL;
    tail = NULL;
}

List_stack::~List_stack()
{
    while (head)
    {
        pop();
    }
}

void List_stack::push(const int &info)
{
    ListNode *newnode = new ListNode(info);

    if (head == NULL && tail == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->nextPtr = newnode;
        newnode->prevPtr = tail;
        tail = newnode;
    }
}
void List_stack::pop()
{
    if (head == NULL && tail == NULL)
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
    ListNode *cur_node = tail;
    while (cur_node)
    {
        cout << cur_node->data;
        if (cur_node->prevPtr != NULL)
        {
            cout << " ";
        }
        cur_node = cur_node->prevPtr;
    }
}
