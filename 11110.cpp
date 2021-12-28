#include <iostream>
using namespace std;
int grid[101][101];
int n;
int arr[202];
int cnt;
int cntarr[101];
int check;

void initgrid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            grid[i][j] = n;
    }
}
void dfs(int x, int y, int val)
{
    grid[x][y] = 0;
    cnt++;
    if (x + 1 < n && grid[x + 1][y] == val)
        dfs(x + 1, y, val);
    if (x - 1 >= 0 && grid[x - 1][y] == val)
        dfs(x - 1, y, val);
    if (y + 1 < n && grid[x][y + 1] == val)
        dfs(x, y + 1, val);
    if (y - 1 >= 0 && grid[x][y - 1] == val)
        dfs(x, y - 1, val);
}
void solve()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt = 0;
            if (grid[i][j] != 0)
            {
                dfs(i, j, grid[i][j]);
                if (cnt != n)
                {
                    check = 1;
                    break;
                }
            }
        }
        if (check == 1)
            break;
    }
}
int main()
{
    while (1 == scanf("%d", &n) && n)
    {
        initgrid();
        int k, p, q;
        char ch;
        for (int i = 1; i < n; i++)
        {
            while (1)
            {
                scanf("%d %d%c", &p, &q, &ch);
                grid[p - 1][q - 1] = i;
                if (ch != ' ')
                    break;
            }
        }
        check = 0;
        solve();
        // cout << "Grid Layout" << endl;
        // for (int i = 0; i < n; i++)
        // {
        // 	for (int j = 0; j < n; j++)
        // 		cout << grid[i][j] << " ";
        // 	cout << endl;
        // }
        // cout << "Cnt Arry" << endl;
        // for (int i = 0; i < n; i++)
        // 	cout << cntarr[i] << " ";
        // cout << endl;
        if (check == 0)
            cout << "good" << endl;
        else
            cout << "wrong" << endl;
    }

    return 0;
}