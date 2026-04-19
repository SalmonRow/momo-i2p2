#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000005
int pos = 0;
char buffer[MAXN];

typedef struct Node
{
    int value;
    struct _Node *left, *right;

} Node;

Node *formatA(char *s)
{
    if (s[pos] == '/' || s[pos] == '\0' || s[pos] == '\n')
        pos++;

    Node *n = malloc(sizeof(Node));

    int val = 0;
    if (isdigit(s[pos]))
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    n->value = val;

    if (s[pos] == '/')
        pos++;
    n->left = formatA(s);
    if (s[pos] == '/')
        pos++;
    n->right = formatA(s);

    if (s[pos] == ')')
        pos++;

    return n;
}

Node *formatB(char *s)
{
    if (s[pos] == '(' && s[pos + 1] == ')')
    {
        pos++;
        return NULL;
    }

    return NULL;
}

int compare(Node *a, Node *b)
{
}

void freet(Node *a)
{
}

int main()
{
    int n;
    scanf("%d", &n);

    fgets(buffer, MAXN, stdin);
    pos = 0;
    Node *roota = formatA(buffer);

    fgets(buffer, MAXN, stdin);
    pos = 0;
    Node *rootb = formatB(buffer);

    if (compare)
        printf("YES");
    else
        printf("NO");

    freet(roota);
    freet(rootb);

    return 0;
}