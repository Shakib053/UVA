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
void fill(int x, int y)
{
    visited[x][y] = 1;
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == '1' && visited[x - 1][y - 1] == 0)
        fill(x - 1, y - 1);
    if (x + 1 < n && y + 1 < n && board[x + 1][y + 1] == '1' && visited[x + 1][y + 1] == 0)
        fill(x + 1, y + 1);
    if (x + 1 < n && board[x + 1][y] == '1' && visited[x + 1][y] == 0)
        fill(x + 1, y);
    if (x - 1 >= 0 && board[x - 1][y] == '1' && visited[x - 1][y] == 0)
        fill(x - 1, y);
    if (y - 1 >= 0 && board[x][y - 1] == '1' && visited[x][y - 1] == 0)
        fill(x, y - 1);
    if (y + 1 < n && board[x][y + 1] == '1' && visited[x][y + 1] == 0)
        fill(x, y + 1);
    if (y - 1 >= 0 && x + 1 < n && board[x + 1][y - 1] == '1' && visited[x + 1][y - 1] == 0)
        fill(x + 1, y - 1);
    if (y + 1 < n && x - 1 >= 0 && board[x - 1][y + 1] == '1' && visited[x - 1][y + 1] == 0)
        fill(x - 1, y + 1);
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && board[i][j] == '1')
            {
                black++;
                fill(i, j);
            }
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
        cout << "Image number " << cnt << " contains " << black << " war eagles." << endl;
        cnt++;
    }

    return 0;
}