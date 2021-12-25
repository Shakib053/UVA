#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int n, m, test;
char s[1223];
int row, col;
char grid[101][101];
int visited[101][101];
int monkey[101][101];
int ans;
int cnt = 0;
void initvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            monkey[i][j] = 0;
    }
}
void update(int num)
{
    cnt++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (visited[i][j] == 1 && monkey[i][j] == 0)
            {
                monkey[i][j] = num;
            }
    }
}
void fill(int x, int y, char ch)
{

    visited[x][y] = 1;

    if (y - 1 >= 0 && visited[x][y - 1] == 0 && grid[x][y - 1] == ch)
        fill(x, y - 1, ch);
    if (y + 1 < m && visited[x][y + 1] == 0 && grid[x][y + 1] == ch)
        fill(x, y + 1, ch);
    if (x - 1 >= 0 && visited[x - 1][y] == 0 && grid[x - 1][y] == ch)
        fill(x - 1, y, ch);
    if (x + 1 < n && visited[x + 1][y] == 0 && grid[x + 1][y] == ch)
        fill(x + 1, y, ch);
    if (x + 1 < n && y + 1 < m && visited[x + 1][y + 1] == 0 && grid[x + 1][y + 1] == ch)
        fill(x + 1, y + 1, ch);
    if (x - 1 >= 0 && y - 1 >= 0 && visited[x - 1][y - 1] == 0 && grid[x - 1][y - 1] == ch)
        fill(x - 1, y - 1, ch);
    if (x + 1 < n && y - 1 >= 0 && visited[x + 1][y - 1] == 0 && grid[x + 1][y - 1] == ch)
        fill(x + 1, y - 1, ch);
    if (x - 1 >= 0 && y + 1 < m && visited[x - 1][y + 1] == 0 && grid[x - 1][y + 1] == ch)
        fill(x - 1, y + 1, ch);
}

void solve()
{
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                ans++;
                fill(i, j, grid[i][j]);
                update(ans);
            }
        }
    }
}
void print()
{
    char format[] = "%?d";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            format[1] = monkey[j] + '0';
            if (j)
                cout << " ";
            cout << format << monkey[i][j];
        }
        cout << endl;
    }
    cout << "%%" << endl;
}
int main()
{
    while (1)
    {
        int k;
        n = 0;
        while (gets(s))
        {
            if (s[0] == '%')
                break;
            m = 0;
            for (k = 0; s[k]; k++)
            {
                if (s[k] != ' ')
                    grid[n][m++] = s[k];
            }
            n++;
        }
        // initvisited();
        // solve();
        // print();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        cout << "%" << endl;
    }

    return 0;
}