#include <iostream>
using namespace std;
int p[31], w[31];
int mw[101];
int g;
int test;
int n;
int solve(int i, int capacity)
{
    int left, right;
    if (i == n)
    {
        return 0;
    }
    left = solve(i + 1, capacity);
    if (capacity >= w[i])
        right = p[i] + solve(i + 1, capacity - w[i]);
    else
        right = 0;
    if (left > right)
        return left;
    else
        return right;
}

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> w[i];
        }
        cin >> g;
        for (int i = 0; i < g; i++)
        {
            cin >> mw[i];
            ans = ans + solve(0, mw[i]);
        }
        cout << ans << endl;
    }

    return 0;
}