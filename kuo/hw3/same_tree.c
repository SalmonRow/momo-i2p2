#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXN 1000005
char buffer[MAXN];
int pos;

typedef struct _Node
{
    int val;
    struct _Node *left, *right;
} Node;

Node *format_A(char *s)
{
    if (s[pos] == '/' || s[pos] == '\0' || s[pos] == '\n')
        return NULL;

    if (s[pos] == '(')
        pos++;

    Node *nn = malloc(sizeof(Node));

    int val = 0; // initial val
    while (isdigit(s[pos]))
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    nn->val = val;

    if (s[pos] == '/')
        pos++;
    nn->left = format_A(s);
    if (s[pos] == '/')
        pos++;
    nn->right = format_A(s);
    if (s[pos] == ')')
        pos++;
    return nn;
}

Node *format_B(char *s)
{
    while (s[pos] == ' ' || s[pos] == '\n')
        pos++;
    if (s[pos] == '(')
    {
        pos++;
        if (s[pos] == ')')
        {
            pos++;
            return NULL;
        }

        return NULL;
    }

    if (!isdigit(s[pos]))
        return NULL;

    Node *nn = malloc(sizeof(Node));

    int val = 0;
    while (isdigit(s[pos]))
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    nn->val = val;

    if (s[pos] == '(')
    {
        pos++;
        nn->left = format_B(s);
        if (s[pos] == ')')
            pos++;
    }
    else
        nn->left = NULL;

    if (s[pos] == '(')
    {
        pos++;
        nn->right = format_B(s);
        if (s[pos] == ')')
            pos++;
    }
    else
        nn->right = NULL;

    return nn;
}
int isSame(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    if (a->val != b->val)
        return 0;

    return isSame(a->left, b->left) && isSame(a->right, b->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main()
{
    int t;
    scanf("%d ", &t);

    fgets(buffer, MAXN, stdin);
    pos = 0;
    Node *rootA = format_A(buffer);

    fgets(buffer, MAXN, stdin);
    pos = 0;
    Node *rootB = format_B(buffer);

    if (isSame(rootA, rootB) == 1)
        printf("YES");
    else
        printf("NO");

    freeTree(rootA);
    freeTree(rootB);
    return 0;
}