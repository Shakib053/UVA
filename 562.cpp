#include <iostream>
#define m 50001
using namespace std;

int n;
int coin[101];
int binary[101];
int total;
int dp[101][m];
int ans;

void initDp()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = -1;
    }
}
int abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}
void read()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
}
int solve(int i, int sum1)
{
    int left, right;
    int sum2;
    if (dp[i][sum1] >= 0)
        return dp[i][sum1];
    if (i == n)
    {
        sum2 = total - sum1;
        return dp[i][sum1] = abs(sum1 - sum2);
    }
    binary[i] = 0;
    left = solve(i + 1, sum1);
    binary[i] = 1;
    right = solve(i + 1, sum1 + coin[i]);
    if (left < right)
        return dp[i][sum1] = left;
    else
        return dp[i][sum1] = right;
}
void solveCase()
{
    total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + coin[i];
    }
    initDp();
    ans = solve(0, 0);
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        read();
        solveCase();
        cout << ans << endl;
    }
    return 0;
}