#include <iostream>
using namespace std;
int m, n;
int price[101], favour[101];
int dp[101][15001];
void initDp()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m + 200; j++)
            dp[i][j] = -1;
    }
}
int solve(int i, int capacity)
{
    if (dp[i][capacity] != -1)
        return dp[i][capacity];
    int left, right;
    if (i == n)
    {
        if (capacity <= m)
            return 0;
        else if (capacity > 2000 && capacity <= m + 200)
            return 0;
        else
            return -2000;
    }

    left = solve(i + 1, capacity);
    if (m + 200 >= capacity + price[i])
        right = solve(i + 1, capacity + price[i]) + favour[i];
    else
        right = -2000;
    if (left > right)
        return dp[i][capacity] = left;
    else
        return dp[i][capacity] = right;
}
int main()
{
    while (2 == (scanf("%d %d", &m, &n)))
    {
        for (int i = 0; i < n; i++)
        {
            cin >> price[i] >> favour[i];
        }
        initDp();
        cout << solve(0, 0) << endl;
        // solve(0, 0, 0);
    }

    return 0;
}