#include <iostream>
using namespace std;
int test;
int v, e;
int queue[1000];
int front, rear;
int grid[1000][1000];
int visited[1000];
int color[1000];
int ans, c0, c1;
int bipartite;
void initcase()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            grid[i][j] = 0;
    }
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    for (int i = 0; i < v; i++)
        color[i] = 0;
    front = 0, rear = 0;
    ans = 0;
}
void print()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
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

void bfs(int start)
{
    visited[start] = 1;
    enqueue(start);
    bipartite = 1;
    color[start] = 0;
    c0 = 1;
    c1 = 0;
    while (front < rear)
    {
        int value = dequeue();
        //cout << value << " ";
        for (int i = 0; i < v; i++)
        {
            if (grid[value][i] == 1)
            {
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    color[i] = 1 - color[value];
                    if (color[i] == 0)
                        c0++;
                    else
                        c1++;
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
        if (bipartite == 0)
            break;
    }
}

void solve()
{
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
            if (bipartite == 0)
            {
                ans = -1;
                break;
            }

            else
            {
                if (c0 + c1 == 1)
                    ans++;
                else if (c0 < c1)
                    ans = ans + c0;
                else
                    ans = ans + c1;
            }
        }
    }
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> v >> e;
        initcase();
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
            grid[y][x] = 1;
        }
        solve();
        //print();

        cout << ans << endl;
    }
    return 0;
}