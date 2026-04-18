#include "function.h"
#include <stdlib.h>
#include <stdio.h>

BTNode *EXPR()
{
    BTNode *n = FACTOR();

    while (pos >= 0 && (expr[pos] == '&' || expr[pos] == '|'))
    {
        BTNode *op = makeNode(expr[pos]);
        pos--;
        op->right = n;
        op->left = EXPR();
        n = op;
    }

    return n;
}
BTNode *FACTOR()
{
    BTNode *n;

    if (expr[pos] == ')')
    {
        pos--;
        n = EXPR();
        pos--;
    }

    else
    {
        n = makeNode(expr[pos]);
        pos--;
    }

    return n;
}

BTNode *makeNode(char c)
{
    BTNode *n = malloc(sizeof(BTNode));

    for (int i = 0; i < NUMSYM; i++)
    {
        if (sym[i] == c)
        {
            n->data = i;
            break;
        }
    }

    n->left = NULL;
    n->right = NULL;
    return n;
}