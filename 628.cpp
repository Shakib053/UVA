#include <iostream>
using namespace std;
int n;
char words[101][257];
char rule[257];
int m, index;
char output[257];
void print()
{
    for (int i = 0; output[i]; i++)
    {
        if (output[i] == '#') // checking whether word is finished or not
            cout << words[index];
        else
            cout << output[i];
    }
    cout << endl;
}
void solve(int i)
{
    if (rule[i] == '\0')
    {
        output[i] = rule[i];
        print();
        return;
    }
    if (rule[i] == '#')
    {
        output[i] = '#';
        solve(i + 1);
    }
    else
    {
        for (int j = 0; j < 10; j++)
        {
            output[i] = '0' + j;
            solve(i + 1);
        }
    }
}
int main()
{
    while (1 == scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            cin >> words[i];
        cin >> m;
        cout << "--" << endl;
        for (int i = 0; i < m; i++)
        {
            cin >> rule;
            for (index = 0; index < n; index++)
            {
                solve(0);
            }
        }
    }

    return 0;
}