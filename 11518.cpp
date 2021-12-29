#include <iostream>
using namespace std;
int test;
int n, m, l;
int grid[10001][10001];
int used[10001];
int cnt;
void initUsed()
{
    for (int i = 1; i <= n; i++)
        used[i] = 0;
}
void initGrid()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            grid[i][j] = 0;
    }
}
void gridPrint()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void counter(int x)
{
    if (used[x] == 1)
        return;
    cnt++;
    used[x] = 1;
}
void solve(int x)
{
    if (used[x] == 1)
        return;
    cnt++;
    used[x] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (grid[x][i] == 1)
        {
            grid[x][i] = 0;
            //used[i] = 1;
            solve(i);
        }
    }
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> m >> l;
        initUsed();
        initGrid();
        for (int i = 0; i < m; i++)
        {
            int p, q;
            cin >> p >> q;
            grid[p][q] = 1;
        }
        cnt = 0;
        //gridPrint();
        for (int i = 0; i < l; i++)
        {
            int z;
            cin >> z;
            solve(z);
        }
        cout << cnt << endl;
    }
    return 0;
}