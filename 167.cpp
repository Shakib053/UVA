#include <iostream>
using namespace std;
int board[8][8];
int visited[8][8];
int ans;
void initVisited()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            visited[i][j] = 0;
    }
}
int rightDiagonal(int i, int j)
{
    while (i >= 0 && j < 8)
    {
        if (visited[i][j] == 1)
            return 0;
        i--;
        j++;
    }
    return 1;
}
int leftDiagonal(int i, int j)
{
    while (i >= 0 && j >= 0)
    {
        if (visited[i][j] == 1)
            return 0;
        i--;
        j--;
    }
    return 1;
}
int check(int i, int j)
{
    while (i >= 0)
    {
        if (visited[i][j] == 1)
            return 0;
        i--;
    }
    return 1;
}
void solve(int i, int sum)
{
    if (i == 8)
    {
        if (sum > ans)
            ans = sum;
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if (rightDiagonal(i, j) && leftDiagonal(i, j) && check(i, j))
        {
            visited[i][j] = 1;
            solve(i + 1, sum + board[i][j]);
            visited[i][j] = 0;
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                cin >> board[i][j];
        }
        initVisited();
        ans = 0;
        solve(0, 0);
        printf("%5d\n", ans);
    }

    return 0;
}