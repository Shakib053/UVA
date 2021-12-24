#include <iostream>
using namespace std;
int visited[101][101];
char board[101][101];
int n, m, Ans;
void initvisited()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
}
void fill(int x, int y)
{
    visited[x][y] = 1;
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == '@' && visited[x - 1][y - 1] == 0)
        fill(x - 1, y - 1);
    if (x + 1 < n && y + 1 < m && board[x + 1][y + 1] == '@' && visited[x + 1][y + 1] == 0)
        fill(x + 1, y + 1);
    if (y - 1 >= 0 && board[x][y - 1] == '@' && visited[x][y - 1] == 0)
        fill(x, y - 1);
    if (y + 1 < m && board[x][y + 1] == '@' && visited[x][y + 1] == 0)
        fill(x, y + 1);
    if (x + 1 < n && y - 1 >= 0 && board[x + 1][y - 1] == '@' && visited[x + 1][y - 1] == 0)
        fill(x + 1, y - 1);
    if (x - 1 >= 0 && y + 1 < m && board[x - 1][y + 1] == '@' && visited[x - 1][y + 1] == 0)
        fill(x - 1, y + 1);
    if (x - 1 >= 0 && board[x - 1][y] == '@' && visited[x - 1][y] == 0)
        fill(x - 1, y);
    if (x + 1 < n && board[x + 1][y] == '@' && visited[x + 1][y] == 0)
        fill(x + 1, y);
}
void solve()
{
    Ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && board[i][j] == '@')
            {
                Ans++;
                fill(i, j);
            }
        }
}
int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        initvisited();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        solve();
        cout << Ans << endl;
    }
}