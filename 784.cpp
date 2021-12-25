#include <stdio.h>
#include <iostream>
char grid[100][100];
int n, test;
void dfs(int x, int y)
{
    if (grid[x][y] == 'X' || grid[x][y] == '#')
        return;
    grid[x][y] = '#';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
void print()
{
    for (int i = 0; i <= n; i++)
    {
        puts(grid[i]);
    }
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; grid[i][j]; j++)
        {
            if (grid[i][j] == '*')
                dfs(i, j);
        }
    }
}
int main()
{
    test;
    scanf("%d ", &test);
    while (test--)
    {
        n = 0;
        while (gets(grid[n]))
        {
            if (grid[n][0] == '_')
                break;
            n++;
        }
        solve();
        print();
    }
    return 0;
}