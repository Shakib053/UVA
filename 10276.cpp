#include <iostream>
using namespace std;
int n;
int test;
int peg[51];
int cnt;
void initpeg()
{
    for (int i = 0; i < n; i++)
        peg[i] = 0;
}
int sqrtCheck(int j)
{
    for (int i = 0; i < 51; i++)
    {
        if (i * i == j)
            return 1;
    }
    return 0;
}
void solve(int i, int val)
{

    if (i == n)
        return;
    if (peg[i] == 0)
    {
        peg[i] = val;
        cnt++;
        solve(i, val + 1);
        return;
    }
    for (int j = 0; j <= i; j++)
    {
        if (sqrtCheck(peg[j] + val) == 1)
        {
            peg[j] = val;
            cnt++;
            solve(i, val + 1);
            return;
        }
    }
    solve(i + 1, val);
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        cnt = 0;
        initpeg();
        solve(0, 1);
        cout << cnt << endl;
    }
    return 0;
}