#include <iostream>
using namespace std;
int positions[8];
int visited[8][8];
int possibility[8];
int ans = 100000;
void initvisited()
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
int checkup(int i, int j)
{
    while (i >= 0)
    {
        if (visited[i][j] == 1)
            return 0;
        i--;
    }
    return 1;
}
void solve(int i)
{
    if (i == 8)
    {
        int cnt = 0;
        for (int i = 0; i < 8; i++)
        {
            if (positions[i] != possibility[i])
                cnt++;
        }
        if (cnt < ans)
            ans = cnt;
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if (leftDiagonal(i, j) == 1 && rightDiagonal(i, j) == 1 && checkup(i, j) == 1)
        {
            visited[i][j] = 1;
            possibility[i] = j + 1;
            solve(i + 1);
            visited[i][j] = 0;
        }
    }
}
int main()
{
    initvisited();
    int c = 1;
    while (scanf("%d", &positions[0]) != EOF)
    {
        for (int i = 1; i < 8; i++)
        {
            cin >> positions[i];
        }
        solve(0);
        cout << "Case " << c << ": " << ans << endl;
        ans = 100000;
        initvisited();
        c++;
    }
    return 0;
}