#include <iostream>
using namespace std;
int n, edges;
int grid[1000][1000];
int visited[1000];
int queue[1000];
int color[1000];
int front, rear, start;
int bipartite;
void initcase()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            grid[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = 0; i < n; i++)
        color[i] = 0;
    bipartite = 1;
}
void enqueue(int val)
{
    queue[rear] = val;
    rear++;
}
int dequeue()
{
    int element = queue[front];
    front++;
    return element;
}

void bfs(int x)
{
    enqueue(x);
    visited[x] = 1;

    while (front < rear)
    {
        int value = dequeue();
        for (int i = 0; i < n; i++)
        {
            if (grid[value][i] == 1)
            {
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    color[i] = 1 - color[value];
                    enqueue(i);
                }
                else if (visited[i] == 1)
                {
                    if (color[i] == color[value])
                    {
                        bipartite = 0;
                        break;
                    }
                }
            }
        }
    }
}
int main()
{
    while (1)
    {
        cin >> n;
        front = 0, rear = 0;

        if (n == 0)
            break;
        cin >> edges;
        initcase();
        for (int i = 0; i < edges; i++)
        {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
            grid[y][x] = 1;
        }
        bfs(0);
        if (bipartite == 0)
            cout << "NOT BICOLORABLE.\n";
        else
            cout << "BICOLORABLE.\n";
    }

    return 0;
}