#include <stdio.h>
#include <iostream>

using namespace std;
int t, n;
char ln[5];
int visited[27];
int path[27][27];
int cnt;
void initvisited()
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

void initpath()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            path[i][j] = 0;
    }
}
void fill(int x)
{
    visited[x] = 1;
    for (int i = 0; i < n; i++)
    {
        if (path[x][i] == 1 && visited[i] == 0)
            fill(i);
    }
}
void solve()
{
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            fill(i);
        }
    }
}
int main()
{
    cin >> t;
    getchar();
    getchar();
    while (t--)
    {
        gets(ln);
        n = ln[0] - 'A' + 1;
        initvisited();
        initpath();
        while (gets(ln))
        {
            if (ln[0] == '\0')
                break;
            int x = ln[0] - 'A';
            int y = ln[1] - 'A';
            path[x][y] = 1;
            path[y][x] = 1;
        }
        solve();
        cout << cnt << endl;
        if (t)
            cout << endl;
    }
    return 0;
}