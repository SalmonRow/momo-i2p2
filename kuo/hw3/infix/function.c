#include "function.h"
#include <stdlib.h>

BTNode *EXPR()
{
}
BTNode *FACTOR()
{
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
void freeTree(BTNode *root)
{
    if (root != NULL)
    {
        freeTree(root->right);
        freeTree(root->left);
        freeTree(root);
    }
}
void printPrefix(BTNode *root)
{
}