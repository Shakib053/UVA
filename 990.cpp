#include <iostream>
using namespace std;
int t, w, n;
int Max;
int first;
int v[31], d[31], bin[31], selected[31];
void update()
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (bin[j] == 1)
            sum = sum + v[j];
    }
    if (sum > Max)
    {
        Max = sum;
        for (int j = 0; j < n; j++)
        {
            selected[j] = bin[j];
        }
    }
}
void solve(int i, int capacity)
{
    if (i == n)
    {
        update();
        return;
    }
    bin[i] = 0;
    solve(i + 1, capacity);
    bin[i] = 1;
    if (capacity >= 3 * w * d[i])
        solve(i + 1, capacity - 3 * w * d[i]);
}
void print()
{
    if (first == 0)
        cout << endl;
    else
        first = 0;
    cout << Max << endl;
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        if (selected[j] == 1)
            cnt++;
    }
    cout << cnt << endl;
    for (int j = 0; j < n; j++)
    {
        if (selected[j] == 1)
            cout << d[j] << " " << v[j] << endl;
    }
}
int main()
{
    first = 1;
    while (scanf("%d %d", &t, &w) == 2)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i] >> v[i];
        }
        solve(0, t);
        print();
    }

    return 0;
}