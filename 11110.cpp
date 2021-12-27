#include <iostream>
using namespace std;
int grid[101][101];
int n;
int arr[202];
int cnt;
void initgrid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            grid[i][j] = 0;
    }
}
int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cnt = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cin >> arr[j];
            }
            for (int k = 0; k < 2 * n; k = k + 2)
            {
                grid[arr[k] - 1][arr[k + 1] - 1] = cnt;
            }
            cnt++;
        }
        cout << "Grid Layout" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}