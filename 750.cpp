#include <iostream>
using namespace std;
int test;
int x, y;
int chessboard[8][8];
int visited[8][8];
int ans[8];

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

    for (int i = 0; i < 8; i++)
    {
        chessboard[ans[i]][i] = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chessboard[i][j];
        }

        cout << endl;
    }
    cout << endl;
    cout << endl;
    // for (int i = 0; i < 8; i++)
    //     cout << ans[i] << " ";
    // cout << endl;
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
        // for (int i = 0; i < 8; i++)
        // {
        //     for (int j = 0; j < 8; j++)
        //         cin >> chessboard[i][j];
        // }
        // chessboard[x - 1][y - 1] = 0;
        initvisited();
        solve(0);
    }

    return 0;
}