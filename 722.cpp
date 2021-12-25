#include <iostream>
using namespace std;
int n, m, test;
int row, col;
char grid[101][101];
int visited[101][101];
int ans;
void initvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    }
}
void fill(int x, int y)
{
    visited[x][y] = 1;
    ans++;
    if (y - 1 >= 0 && visited[x][y - 1] == 0 && grid[x][y - 1] == '0')
        fill(x, y - 1);
    if (y + 1 < m && visited[x][y + 1] == 0 && grid[x][y + 1] == '0')
        fill(x, y + 1);
    if (x - 1 >= 0 && visited[x - 1][y] == 0 && grid[x - 1][y] == '0')
        fill(x - 1, y);
    if (x + 1 < n && visited[x + 1][y] == 0 && grid[x + 1][y] == '0')
        fill(x + 1, y);
}
void solve()
{
    ans = 0;
    fill(row - 1, col - 1);
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        cin >> row >> col;
        initvisited();
        solve();
        cout << ans << endl;
        if (test)
            cout << endl;
    }

    return 0;
}