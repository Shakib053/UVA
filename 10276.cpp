#include <iostream>

using namespace std;
int n, v;
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
void solve(int i)
{
    if (i == n)
        return;
    if (peg[i] == 0)
    {
        peg[i] = v;
        v++;
        cnt++;
        solve(i);
        return;
    }
    for (int j = 0; j <= i; j++)
    {
        if (sqrtCheck(peg[j] + v) == 1)
        {
            peg[j] = v;
            v++;
            cnt++;
            solve(i);
            return;
        }
    }
    solve(i + 1);
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        cnt = 0;
        initpeg();
        v = 1;
        solve(0);
        cout << cnt << endl;
    }

    return 0;
}