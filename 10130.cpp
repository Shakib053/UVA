#include <iostream>
using namespace std;
int p[1001], w[1001];
int mw[1001];
int g;
int test;
int n;
int dp[1001][31];
void initDp()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 31; j++)
            dp[i][j] = -1;
    }
}
int solve(int i, int capacity)
{
    int left, right;
    if (dp[i][capacity] != -1)
        return dp[i][capacity];
    if (i == n)
    {
        return dp[i][capacity] = 0;
    }
    left = solve(i + 1, capacity);
    if (capacity >= w[i])
        right = p[i] + solve(i + 1, capacity - w[i]);
    else
        right = 0;
    if (left > right)
        return dp[i][capacity] = left;
    else
        return dp[i][capacity] = right;
}

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> w[i];
        }
        cin >> g;
        initDp();
        for (int i = 0; i < g; i++)
        {
            cin >> mw[i];
            ans = ans + solve(0, mw[i]);
        }
        cout << ans << endl;
    }

    return 0;
}