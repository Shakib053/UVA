#include <iostream>
using namespace std;
int n, tracks;
int tn[21];
int bin[21];
int path[21];
int ans;
void update()
{
    for (int i = 0; i < tracks; i++)
        path[i] = bin[i];
}
void solve(int i, int sum)
{
    if (i == tracks)
    {
        if (sum > ans)
        {
            update();
            ans = sum;
        }
        return;
    }
    bin[i] = 0;
    solve(i + 1, sum);
    if (sum + tn[i] <= n)
    {
        bin[i] = 1;
        solve(i + 1, sum + tn[i]);
    }
}
int main()
{
    while (2 == scanf("%d %d", &n, &tracks))
    {
        for (int i = 0; i < tracks; i++)
            cin >> tn[i];
        ans = 0;
        solve(0, 0);
        for (int i = 0; i < tracks; i++)
        {
            if (path[i] == 1)
                cout << tn[i] << " ";
        }
        cout << "sum:" << ans << endl;
    }
    return 0;
}