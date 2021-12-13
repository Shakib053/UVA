#include <iostream>
using namespace std;
int n, m;
int ans;
int visited[26][26];
int path[26][26];
int Ans;
void initCase()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
            path[i][j] = 0;
        }
    }
}
int depth(int i)
{
    int max = 0, temp;
    for (int j = 0; j < n; j++)
    {
        if (visited[i][j] == 0 && path[i][j] == 1)
        {
            visited[i][j] = 1;
            visited[j][i] = 1;
            temp = depth(j);
            visited[i][j] = 0;
            visited[j][i] = 0;
            if (temp > max)
                max = temp;
        }
    }
    return max + 1;
}
void solve()
{
    int temp, ans = 0;
    for (int i = 0; i < n; i++)
    {
        temp = depth(i);
        if (temp > ans)
        {
            ans = temp;
        }
    }
    Ans = ans;
}
int main()
{
    while (2 == (scanf("%d %d", &n, &m)))
    {
        if (n == 0 && m == 0)
            break;
        initCase();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            path[x][y] = 1;
            path[y][x] = 1;
        }
        solve();
        cout << Ans - 1 << endl;
    }

    return 0;
}