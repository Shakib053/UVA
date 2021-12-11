#include <iostream>
using namespace std;
int m, n;
int price[101], favour[101];
int solve(int i, int capacity, int selected)
{
    int left, right;
    if (i == n)
    {
        if (capacity <= m)
            return selected;
        // cout << capacity << " " << selected << endl;
        else if (capacity > 2000 && capacity <= m + 200)
            //  return selected;
            // cout << capacity << " " << selected << endl;
            // return;
            return selected;
        else
            return 0;
    }
    left = solve(i + 1, capacity, selected);
    if (m + 200 >= capacity + price[i])
        right = solve(i + 1, capacity + price[i], selected + favour[i]);
    else
        right = -2000;
    // left = solve(i + 1, capacity, selected);
    // if (m + 200 >= capacity + price[i])
    // {
    //     right = solve(i + 1, capacity + price[i], selected + favour[i]);
    // }
    // // else
    // //     right = -2000;
    if (left > right)
        return left;
    else
        return right;
}
int main()
{
    while (2 == (scanf("%d %d", &m, &n)))
    {
        for (int i = 0; i < n; i++)
        {
            cin >> price[i] >> favour[i];
        }
        cout << solve(0, 0, 0) << endl;
        // solve(0, 0, 0);
    }

    return 0;
}