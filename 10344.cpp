#include <iostream>
using namespace std;
int numbers[6];
int visited[6];
void initvisited()
{
    for (int j = 0; j < 5; j++)
        visited[j] = 0;
}
int solve(int i, int result)
{
    if (i == 5 && result == 23)
        return 1;
    for (int j = 0; j < 5; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            if (solve(i + 1, result + numbers[j]) == 1)
                return 1;
            if (solve(i + 1, result - numbers[j]) == 1)
                return 1;
            if (solve(i + 1, result * numbers[j]) == 1)
                return 1;
            visited[j] = 0;
        }
    }
    return 0;
}
int main()
{
    while (1)
    {
        int cnt = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> numbers[i];
            if (numbers[i] == 0)
                cnt++;
        }
        if (cnt == 5)
            return 0;
        initvisited();
        int flag = 0;
        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                if (solve(1, numbers[i]) == 1)
                {
                    cout << "Possible\n";
                    flag = 1;
                }
                visited[i] = 0;
            }
        }
        if (flag == 0)
            cout << "Impossible\n";
    }

    return 0;
}