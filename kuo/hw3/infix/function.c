#include "function.h"
#include <stdlib.h>
#include <stdio.h>

BTNode *EXPR()
{
    BTNode *node = FACTOR();

    while (pos >= 0 && (expr[pos] == '&' || expr[pos] == '|'))
    {
        BTNode *op = makeNode(expr[pos]);
        pos--;
        op->right = node;
        op->left = EXPR();
        node = op;
    }

    return node;
}
BTNode *FACTOR()
{
    BTNode *node;

    if (expr[pos] == ')')
    {
        pos--;
        node = EXPR();
        pos--;
    }
    else
    {
        node = makeNode(expr[pos]);
        pos--;
    }

    return node;
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