#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXN 1000005
char bufferA[MAXN];
char bufferB[MAXN];
int pos;

typedef struct _Node
{
    int val;
    struct _Node *left, *right;
} Node;

Node *format_A(char *s)
{
    // Base cases for empty subtrees or end of strings
    if (s[pos] == '/' || s[pos] == '\0' || s[pos] == '\n' || s[pos] == '\r' || s[pos] == ')')
        return NULL;

    if (s[pos] == '(')
        pos++; // Consume outer '('

    Node *nn = malloc(sizeof(Node));
    int val = 0;

    while (isdigit(s[pos]))
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    nn->val = val;

    if (s[pos] == '/')
        pos++; // Consume separator
    nn->left = format_A(s);

    if (s[pos] == '/')
        pos++; // Consume separator
    nn->right = format_A(s);

    if (s[pos] == ')')
        pos++; // Consume outer ')'

    return nn;
}

Node *format_B(char *s)
{
    // Skip any trailing whitespaces/newlines safely
    while (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\r')
        pos++;

    // Base case: If no digit, it's an empty node (e.g., inside "()")
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
        pos++; // Consume left child '('
        nn->left = format_B(s);
        if (s[pos] == ')')
            pos++; // Consume left child ')'
    }
    else
    {
        nn->left = NULL;
    }

    if (s[pos] == '(')
    {
        pos++; // Consume right child '('
        nn->right = format_B(s);
        if (s[pos] == ')')
            pos++; // Consume right child ')'
    }
    else
    {
        nn->right = NULL;
    }

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
    if (scanf("%d ", &t) != 1)
        return 0;

    fgets(bufferA, MAXN, stdin);
    pos = 0;
    Node *rootA = format_A(bufferA);

    fgets(bufferB, MAXN, stdin);
    pos = 0;
    Node *rootB = format_B(bufferB);

    if (isSame(rootA, rootB))
        printf("YES\n");
    else
        printf("NO\n");

    freeTree(rootA);
    freeTree(rootB);
    return 0;
}