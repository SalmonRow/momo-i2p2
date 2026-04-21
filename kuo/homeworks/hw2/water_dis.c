#include <stdio.h>
#define MAXN 105

// globals
int grid[MAXN][MAXN];
int visited[MAXN][MAXN];
int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int n, int m)
{
    int head = 0, tail = 0, count = 0;
    qx[tail] = 0;
    qy[tail] = 0;
    tail++;
    visited[0][0] = 1;
    count++;

    while (head < tail)
    {
        int cx = qx[head];
        int cy = qy[head];
        head++;

        for (int j = 0; j < 4; j++)
        {
            int nx = cx + dx[j];
            int ny = cy + dy[j];
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && !visited[nx][ny] && grid[nx][ny] <= grid[cx][cy])
            {
                visited[nx][ny] = 1;
                qx[tail] = nx;
                qy[tail] = ny;
                tail++;
                count++;
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
        for (int ii = 0; ii < m; ii++)
        {
            scanf("%d", &grid[i][ii]);
        }
    }
    printf("%d\n", bfs(n, m));
    return 0;
}