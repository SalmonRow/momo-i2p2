#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

typedef struct Edge
{
    int to;
    int weight;
    struct Edge *next;
} Edge;

Edge *graph[MAXN];

void add_edge(int u, int v, int w)
{
    Edge *new = (Edge *)malloc(sizeof(Edge));
    new->to = v;
    new->weight = w;
    new->next = graph[u];
    graph[u] = new;
}

void dfs();

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        /*
        u = one endpoint (node)
        v = the other endpoint (the other node)
        w = the cost of the connection between u and v
        */
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w); // walk foward
        add_edge(v, u, w); // walk back
    }
    return 0;
}