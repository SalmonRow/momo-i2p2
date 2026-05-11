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
long long total_weight = 0;
long long max_distance = 0;
int farthest = 0;

void add_edge(int u, int v, int w)
{
    Edge *new = (Edge *)malloc(sizeof(Edge));
    new->to = v;
    new->weight = w;
    new->next = graph[u];
    graph[u] = new;
}

void dfs(int current_node, int parent_node, long long current_distance)
{
    if (current_distance > max_distance)
    {
        max_distance = current_distance;
        farthest = current_node;
    }

    Edge *curr = graph[current_node];
    while (curr != NULL)
    {
        int neighbor = curr->to;
        int weight = curr->weight;

        if (neighbor != parent_node)
        {
            dfs(neighbor, current_node, current_distance + weight);
        }

        curr = curr->next;
    }
}

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
        total_weight += w;
        add_edge(u, v, w); // walk foward
        add_edge(v, u, w); // walk back
    }

    // the first walk
    farthest = 1;
    max_distance = 0;
    dfs(1, -1, 0); // start from the first one

    int the_end = farthest;

    // the second walk;
    max_distance = 0;
    dfs(the_end, -1, 0);

    // final math shortcuts
    long long ans = (2 * total_weight) - max_distance;
    printf("%lld\n", ans);
    return 0;
}