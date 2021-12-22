#include <iostream>
using namespace std;
int x, y;
int a, b;
char position;
char instructions[101];
int flag;
int visited[100][100] = {};
void solve()
{
    flag = 0;
    for (int i = 0; instructions[i]; i++)
    {
        if (instructions[i] == 'L')
        {
            if (position == 'W')
            {
                position = 'S';
            }
            else if (position == 'N')
            {
                position = 'W';
            }
            else if (position == 'E')
            {
                position = 'N';
            }
            else if (position == 'S')
            {
                position = 'E';
            }
        }
        else if (instructions[i] == 'F')
        {
            if (position == 'W')
            {
                a = a - 1;
            }
            else if (position == 'N')
            {
                b = b + 1;
            }
            else if (position == 'E')
            {
                a = a + 1;
            }
            else if (position == 'S')
            {
                b = b - 1;
            }
        }
        else if (instructions[i] == 'R')
        {
            if (position == 'W')
            {
                position = 'N';
            }
            else if (position == 'N')
            {
                position = 'E';
            }
            else if (position == 'E')
            {
                position = 'S';
            }
            else if (position == 'S')
            {
                position = 'W';
            }
        }
        if (a < 0 || b < 0 || a > x || b > y)
        {

            if (position == 'W')
            {
                a = a + 1;
            }
            else if (position == 'N')
            {
                b = b - 1;
            }
            else if (position == 'E')
            {
                a = a - 1;
            }
            else if (position == 'S')
            {
                b = b + 1;
            }
            if (visited[a][b] == 1)
                continue;
            flag = 1;
            visited[a][b] = 1;
            break;
        }
    }
}
int main()
{
    cin >> x >> y;
    while (cin >> a >> b >> position)
    {
        cin >> instructions;
        solve();
        if (flag == 0)
            cout << a << " " << b << " " << position << endl;
        else
            cout << a << " " << b << " " << position << " LOST" << endl;
    }

    return 0;
}