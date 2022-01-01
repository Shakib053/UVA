#include <iostream>
using namespace std;
int grid[500][500];
int visited[500];
int queue[1000];
int bipartite;
int color[500];
int front = 0, rear = 0;
int test, n, edges, cnt0, cnt1, ans;
void initcase()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            grid[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    for (int i = 1; i <= n; i++)
        color[i] = 0;
    ans = 0;
    front = 0, rear = 0;
}
void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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
    cnt0 = 1, cnt1 = 0;
    while (front < rear)
    {
        int value = dequeue();
        for (int i = 1; i <= n; i++)
        {
            if (grid[value][i] == 1)
            {
                if (visited[i] == 0)
                {
                    color[i] = 1 - color[value];
                    if (color[i] == 0)
                        cnt0++;
                    else if (color[i] == 1)
                        cnt1++;
                    visited[i] = 1;
                    enqueue(i);
                }
                else if (visited[i] == 1)
                {
                    if (color[i] == color[value])
                    {
                        bipartite = 0;
                    }
                }
            }
        }
    }
    if (bipartite == 1)
    {
        if (cnt0 > cnt1)
            ans = ans + cnt0;
        else
            ans = ans + cnt1;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
        }
    }
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        initcase();
        for (int i = 1; i <= n; i++)
        {
            cin >> edges;
            for (int j = 0; j < edges; j++)
            {
                int x;
                cin >> x;
                grid[i][x] = 1;
                grid[x][i] = 1;
            }
        }
        // print();
        solve();
        cout << ans << endl;
    }
}