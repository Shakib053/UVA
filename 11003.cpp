#include <iostream>
using namespace std;
int n;
int weights[3001], maxLoad[3001];
int ans;
void solve(int i, int cap, int cnt)
{
    int left, right;
    if (i == n)
    {
        if (cnt > ans)
            ans = cnt;
        return;
    }
    solve(i + 1, cap, cnt);
    if (cap >= weights[i])
    {
        if (cap >= weights[i] + maxLoad[i])
            solve(i + 1, maxLoad[i], cnt + 1);
        else
            solve(i + 1, cap - weights[i], cnt + 1);
    }
}
int main()
{
    while (1 == scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> weights[i] >> maxLoad[i];
        ans = 0;
        solve(0, 3001, 0);
        cout << ans << endl;
    }

    return 0;
}