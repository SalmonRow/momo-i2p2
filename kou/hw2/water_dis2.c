#include <stdio.h>
#define MAXN 101

// Implementation using struck
typedef struct
{
    int r, c;
} Block;

// globals
int grid[MAXN][MAXN];
int visited[MAXN][MAXN] = {0};
Block q[MAXN * MAXN];
Block d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int n, int m)
{
    int head = 0, tail = 0, count = 0;

    // initial state
    q[tail] = (Block){0, 0};
    visited[0][0] = 1;
    tail++;
    count++;

    while (head < tail)
    {
        Block cur = q[head];
        head++;

        for (int ii = 0; ii < 4; ii++)
        {
            int nr = cur.r + d[ii].r;
            int nc = cur.c + d[ii].c;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] != 1 && grid[cur.r][cur.c] >= grid[nr][nc])
            {
                visited[nr][nc] = 1;
                count++;
                q[tail] = (Block){nr, nc};
                tail++;
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("%d\n", bfs(n, m));
    return 0;
}
