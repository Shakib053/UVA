#include <iostream>
using namespace std;
int test, n, m;
char grid[101][101];
int frequency[26];
int w = 1;
void initcase()
{
    for (int i = 0; i < 26; i++)
    {
        frequency[i] = 0;
    }
}
void dfs(int x, int y, char ch1)
{
    grid[x][y] = 0;
    if (x + 1 < n && grid[x + 1][y] == ch1)
        dfs(x + 1, y, ch1);
    if (x - 1 >= 0 && grid[x - 1][y] == ch1)
        dfs(x - 1, y, ch1);
    if (y + 1 < m && grid[x][y + 1] == ch1)
        dfs(x, y + 1, ch1);
    if (y - 1 >= 0 && grid[x][y - 1] == ch1)
        dfs(x, y - 1, ch1);
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                char ch = grid[i][j];
                frequency[grid[i][j] - 'a']++;
                dfs(i, j, ch);
            }
        }
    }
}
void print()
{
    cout << "World #" << w << endl;
    int maxi = 0;
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > maxi)
            maxi = frequency[i];
    }
    while (maxi)
    {
        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] == maxi)
                cout << char(i + 'a') << ": " << frequency[i] << endl;
        }
        maxi--;
    }
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        initcase();
        solve();
        print();
        w++;
    }
}