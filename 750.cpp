#include <iostream>
using namespace std;
int test;
int x, y;
int chessboard[8][8];
int visited[8][8];
int ans[8];
int cnt = 0;
int times = 1;
void initboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            chessboard[i][j] = 0;
    }
}
void initvisited()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            visited[i][j] = 0;
    }
}
int leftdiagonal(int i, int j)
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
int rightdiagonal(int i, int j)
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
int finalcheck(int i, int j)
{
    {
        while (i >= 0)
        {
            if (visited[i][j] == 1)
                return 0;
            i--;
        }
    }
    return 1;
}
void print()
{
    initboard();
    if (cnt == 0)
    {
        cout << "SOLN"
             << "       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        cnt = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        chessboard[ans[i]][i] = 1;
    }
    int flag = 0;
    if (chessboard[x - 1][y - 1] == 1)
        flag = 1;
    if (flag == 1)
    {
        // cout << " " << times << "    ";
        printf("%2d      ", times);
        times++;
        for (int i = 0; i < 8; i++)
        {
            if (i != 7)
                cout << ans[i] + 1 << " ";
            else
                cout << ans[i] + 1;
        }
        cout << endl;
    }
}
void solve(int i)
{
    if (i == 8)
    {
        print();
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if (leftdiagonal(i, j) == 1 && rightdiagonal(i, j) == 1 &&
            finalcheck(i, j) == 1)
        {
            visited[i][j] = 1;
            ans[i] = j;
            solve(i + 1);
            visited[i][j] = 0;
        }
    }
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> x >> y;
        initboard();
        initvisited();
        solve(0);
        times = 1, cnt = 0;
        if (test)
            cout << endl;
    }

    return 0;
}