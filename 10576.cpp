#include <iostream>
using namespace std;
int s, d;
int earn[12];
int solve(int i, int sum1, int sum2)
{
    int left, right;
    if (i >= 5 && sum2 >= 0)
        return -1;
    if (i == 12)
        return sum1;
    if (i >= 5)
        sum2 = sum2 - earn[i - 5];
    earn[i] = s;
    left = solve(i + 1, sum1 + s, sum2 + s);
    earn[i] = -d;
    right = solve(i + 1, sum1 - d, sum2 - d);
    if (left > right)
        return left;
    else
        return right;
}
int main()
{
    while (cin >> s >> d)
    {
        int ans = solve(0, 0, 0);
        if (ans >= 0)
            cout << ans << endl;
        else
            cout << "Deficit\n";
    }
    return 0;
}
