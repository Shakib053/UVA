#include <iostream>
#include <stdio.h>
using namespace std;
int test;
int n, m;
char grid[26][26];
int visited[26][26];
int ans, cnt;
void initvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    }
}
void dfs(int x, int y)
{
    ans++;
    visited[x][y] = 1;
    if (x + 1 < n && y + 1 < m && visited[x + 1][y + 1] == 0 && grid[x + 1][y + 1] == '1')
        dfs(x + 1, y + 1);
    if (x - 1 >= 0 && y - 1 >= 0 && visited[x - 1][y - 1] == 0 && grid[x - 1][y - 1] == '1')
        dfs(x - 1, y - 1);
    if (x + 1 < n && visited[x + 1][y] == 0 && grid[x + 1][y] == '1')
        dfs(x + 1, y);
    if (x - 1 >= 0 && visited[x - 1][y] == 0 && grid[x - 1][y] == '1')
        dfs(x - 1, y);
    if (y + 1 < m && visited[x][y + 1] == 0 && grid[x][y + 1] == '1')
        dfs(x, y + 1);
    if (y - 1 >= 0 && visited[x][y - 1] == 0 && grid[x][y - 1] == '1')
        dfs(x, y - 1);
    if (x + 1 < n && y - 1 >= 0 && visited[x + 1][y - 1] == 0 && grid[x + 1][y - 1] == '1')
        dfs(x + 1, y - 1);
    if (x - 1 >= 0 && y + 1 < m && visited[x - 1][y + 1] == 0 && grid[x - 1][y + 1] == '1')
        dfs(x - 1, y + 1);
}
int main()
{
    cin >> test;
    getchar();
    getchar();
    while (test--)
    {
        n = 0;
        while (gets(grid[n]))
        {
            if (!grid[n][0])
                break;
            n++;
        }
        m = 0;
        for (int i = 0; grid[0][i]; i++)
            m++;
        initvisited();
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == '1')
                {
                    ans = 0;
                    dfs(i, j);
                    if (ans > cnt)
                        cnt = ans;
                }
            }
        }
        cout << cnt << endl;
        if (test)
            cout << endl;
    }
    return 0;
}