#include <iostream>
using namespace std;
char grid[50][50];
int test, b, w;
int black[10][10];
int white[10][10];
void initvisited()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            black[i][j] = 0;
            white[i][j] = 0;
        }
}
void solveBlack(int x, int y)
{

    black[x][y] = 1;
    if (x + 1 < 9 && black[x + 1][y] == 0 && grid[x + 1][y] == '.')
        solveBlack(x + 1, y);
    if (x - 1 >= 0 && black[x - 1][y] == 0 && grid[x - 1][y] == '.')
        solveBlack(x - 1, y);
    if (y + 1 < 9 && black[x][y + 1] == 0 && grid[x][y + 1] == '.')
        solveBlack(x, y + 1);
    if (y - 1 >= 0 && black[x][y - 1] == 0 && grid[x][y - 1] == '.')
        solveBlack(x, y - 1);
}
void solveWhite(int x, int y)
{

    white[x][y] = 1;
    if (x + 1 < 9 && white[x + 1][y] == 0 && grid[x + 1][y] == '.')
        solveWhite(x + 1, y);
    if (x - 1 >= 0 && white[x - 1][y] == 0 && grid[x - 1][y] == '.')
        solveWhite(x - 1, y);
    if (y + 1 < 9 && white[x][y + 1] == 0 && grid[x][y + 1] == '.')
        solveWhite(x, y + 1);
    if (y - 1 >= 0 && white[x][y - 1] == 0 && grid[x][y - 1] == '.')
        solveWhite(x, y - 1);
}
int main()
{
    cin >> test;
    while (test--)
    {
        b = 0, w = 0;
        for (int i = 0; i < 9; i++)
        {
            cin >> grid[i];
        }
        initvisited();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 'X')
                {
                    solveBlack(i, j);
                }
                if (grid[i][j] == 'O')
                {
                    solveWhite(i, j);
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (black[i][j] != white[i][j])
                {
                    if (black[i][j] == 1)
                        b++;
                    else
                        w++;
                }
            }
        }
        cout << "Black " << b << " White " << w << endl;
    }

    return 0;
}