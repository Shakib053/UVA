#include <iostream>
using namespace std;
int n;
int visited[101];
int bin[101];
int path[11][11];
int matrix[11][11];
int m, count;
void initvisited()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}
void print()
{
    cout << "(";
    for (int i = 0; i <= m; i++)
    {
        if (i != m)
        {
            cout << bin[i] + 1 << ",";
        }
        else
            cout << bin[i] + 1;
    }
    cout << ")";
    cout << endl;
}
void solve(int level, int i)
{
    bin[level] = i;
    if (level == m)
    {
        count++;
        print();
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0 && matrix[i][j] == 1)
        {
            visited[j] = 1;
            solve(level + 1, j);
            visited[j] = 0;
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%d %d", &n, &m);
        int x = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        initvisited();
        visited[0] = 1;
        count = 0;
        solve(0, 0);
        if (count == 0)
            cout << "no walk of length " << x << endl;
        if (scanf("%d", &n) == -1)
            break;
        else
            cout << endl;
    }

    return 0;
}