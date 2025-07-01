#include <bits/stdc++.h>
using namespace std;
int main()
{
    int goal, cur = 2, result = 0, all = 35;
    while (all--)
    {
        cin >> goal;
        if (goal == 0)
            break;
        if (goal == 2)
        {
            result += cur;
            cur += 2;
        }
        if (goal == 1)
        {
            result += 1;
            cur = 2;
        }
    }
    cout << result << endl;
    return 0;
}
