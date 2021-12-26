#include <stdio.h>
char grid[100][100];
int n;
void read()
{
    n = 1;
    while (gets(grid[n]))
    {
        if (grid[n][0] == '_')
            break;
        n++;
    }
}

void dfs(int x, int y, char ch)
{
    grid[x][y] = ch;
    if (grid[x + 1][y] == ' ')
        dfs(x + 1, y, ch);
    if (grid[x - 1][y] == ' ')
        dfs(x - 1, y, ch);
    if (grid[x][y - 1] == ' ')
        dfs(x, y - 1, ch);
    if (grid[x][y + 1] == ' ')
        dfs(x, y + 1, ch);
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; grid[i][j]; j++)
        {
            if (grid[i][j] != 'X' && grid[i][j] != ' ')
                dfs(i, j, grid[i][j]);
        }
    }
}
void print()
{
    for (int i = 0; i <= n; i++)
        puts(grid[i]);
}
int main()
{
    while (1)
    {
        n = 0;
        while (1)
        {
            if (!gets(grid[n]))
                return 0;
            if (grid[n][0] == '_')
                break;
            n++;
        }
        solve();
        print();
    }
    return 0;
}