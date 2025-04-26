#include <bits/stdc++.h>
using namespace std;
const int k = 7;
int startsalary[k] = {3500, 3500 + 1500, 3500 + 4500, 3500 + 9000, 3500 + 35000, 3500 + 55000, 3500 + 80000};
int rates[k + 1] = {3, 10, 20, 25, 30, 35, 45};
int facts[k];
int main()
{
    facts[0] = startsalary[0];
    for (int i = 1; i < k; i++)
    {
        facts[i] = facts[i - 1] + (startsalary[i] - startsalary[i - 1]) * (1 - rates[i - 1] / 100.0);
        // cout << facts[i] << " ";
    }
    int t, s;
    cin >> t;
    int index;
    for (index = 0; index < k; index++)
    {
        if (t <= facts[index])
            break;
    }
    if (index == 0)
    {
        s = t;
    }
    else
    {
        s = startsalary[index - 1] + (t - facts[index - 1]) / (1 - rates[index - 1] / 100.0);
    }
    cout << s << endl;
    return 0;
}
