#include "function.h"
#include <stdlib.h>
#include <stdio.h>

// typedef struct _Node
// {
//     TokenSet data;
//     struct _Node *left, *right;
// } BTNode;

BTNode *EXPR()
{
    BTNode *nn = FACTOR();

    while (pos >= 0 && (expr[pos] == '&' || expr[pos] == '|'))
    {
        BTNode *op = makeNode(expr[pos]);
        pos--;
        op->right = nn;
        op->left = EXPR();
        nn = op;
    }

    return nn;
}

BTNode *FACTOR()
{
    BTNode *nn;

    if (expr[pos] == ')')
    {
        pos--;
        nn = EXPR();
        pos--;
    }
    else
    {
        nn = makeNode(expr[pos]);
        pos--;
    }

    return nn;
}

BTNode *makeNode(char c)
{
    BTNode *nn = (BTNode *)malloc(sizeof(BTNode));

    for (int i = 0; i < NUMSYM; i++)
    {
        if (sym[i] == c)
        {
            nn->data = i;
            break;
        }
    }

    nn->left = NULL;
    nn->right = NULL;
    return nn;
}