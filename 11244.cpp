#include <iostream>
using namespace std;
char grid[101][101];
int n, m;
int cnt;
int dfs(int x, int y)
{
    if (x + 1 < n && grid[x + 1][y] == '*')
        return 0;
    if (x - 1 >= 0 && grid[x - 1][y] == '*')
        return 0;
    if (y + 1 < m && grid[x][y + 1] == '*')
        return 0;
    if (y - 1 >= 0 && grid[x][y - 1] == '*')
        return 0;
    if (x + 1 < n && y + 1 < m && grid[x + 1][y + 1] == '*')
        return 0;
    if (x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == '*')
        return 0;
    if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == '*')
        return 0;
    if (x - 1 >= 0 && y + 1 < m && grid[x - 1][y + 1] == '*')
        return 0;
    return 1;
}
void solve()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
            {
                if (dfs(i, j) == 1)
                    cnt++;
            }
        }
    }
}
int main()
{
    while (2 == scanf("%d %d", &n, &m))
    {
        if (n == 0 || m == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        cnt = 0;
        solve();
        cout << cnt << endl;
    }
    return 0;
}