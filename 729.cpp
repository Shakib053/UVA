#include <iostream>
using namespace std;
int n, h;
int bin[100001];
int visited[100001];
int test;
void initvisited()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}
void print()
{
    for (int i = 0; i < n; i++)
        cout << bin[i];
    cout << endl;
}
void solve(int i)
{
    if (i == n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bin[i] == 1)
                cnt++;
            if (cnt > h)
                break;
        }
        if (cnt == h)
            print();
        return;
    }
    bin[i] = 0;
    solve(i + 1);
    bin[i] = 1;
    solve(i + 1);
}
void printcase()
{
    if (test)
        cout << endl;
}
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> h;
        initvisited();
        solve(0);
        printcase();
    }

    return 0;
}