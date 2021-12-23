#include <iostream>
using namespace std;
int n;
char board[201][201];
int visited[201][201];
int black;
int cnt = 1;
void initvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
}
int fill(int x, int y)
{
    if (x == n - 1)
        return 1;
    visited[x][y] = 1;
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'b' && visited[x - 1][y - 1] == 0 && fill(x - 1, y - 1) == 1)
        return 1;
    if (x + 1 < n && y + 1 < n && board[x + 1][y + 1] == 'b' && visited[x + 1][y + 1] == 0 && fill(x + 1, y + 1) == 1)
        return 1;
    if (x + 1 < n && board[x + 1][y] == 'b' && visited[x + 1][y] == 0 && fill(x + 1, y) == 1)
        return 1;
    if (x - 1 >= 0 && board[x - 1][y] == 'b' && visited[x - 1][y] == 0 && fill(x - 1, y) == 1)
        return 1;
    if (y - 1 >= 0 && board[x][y - 1] == 'b' && visited[x][y - 1] == 0 && fill(x, y - 1) == 1)
        return 1;
    if (y + 1 < n && board[x][y + 1] == 'b' && visited[x][y + 1] == 0 && fill(x, y + 1) == 1)
        return 1;
    return 0;
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (visited[0][i] == 0 && board[0][i] == 'b' && fill(0, i) == 1)
        {
            black = 1;
            break;
        }
    }
}
int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        initvisited();
        black = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }
        solve();
        if (black == 1)
            cout << cnt << " " << 'B' << endl;
        else
            cout << cnt << " " << 'W' << endl;
        cnt++;
    }

    return 0;
}