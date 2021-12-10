#include <iostream>
using namespace std;
int weights[21];
int n;
int total;
int test;
int abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
int solve(int i, int cap)
{
    int left, right;
    if (i == n)
    {
        return abs(cap - (total - cap));
    }
    left = solve(i + 1, cap);
    right = solve(i + 1, cap + weights[i]);
    if (left < right)
        return left;
    else
        return right;
}
int main()
{
    cin >> test;
    while (test--)
    {
        char ch;
        n = 0;
        total = 0;
        while (2 == (scanf("%d%c", &weights[n], &ch)))
        {
            total = total + weights[n];
            n++;
            if (ch != ' ')
                break;
        }
        if (total % 2 == 1)
            cout << "NO" << endl;
        else
        {
            int x = solve(0, 0);
            if (x == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}