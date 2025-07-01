#include <bits/stdc++.h>
using namespace std;
int fast[105];
int slow[105];
int tim[105];
int former[105];
bool bedepend[105];
bool isupdate[105];
void calculate(int i, int &fasttim)
{
    if (former[i] == 0)
        return;
    fasttim += tim[former[i]];
    calculate(former[i], fasttim);
}
int main()
{
    bool flag = true;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int f;
        cin >> f;
        former[i] = f;
        bedepend[f] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        tim[i] = t;
    }
    for (int i = 1; i <= m; i++)
    {
        int fasttim = 1;
        calculate(i, fasttim);
        fast[i] = fasttim;
        cout << fast[i] << " ";
        if (fast[i] + tim[i] - 1 > n)
            flag = false;
    }
    if (flag)
    {
        cout << endl;
        for (int i = 1; i <= m; i++)
        {
            slow[i] = n - tim[i] + 1;
        }
        for (int i = 1; i <= m; i++)
        {
            if (bedepend[i] == false)
            {
                int cur = i;
                while (former[cur])
                {
                    slow[former[cur]] = min(slow[former[cur]], slow[cur] - tim[former[cur]]);
                    cur = former[cur];
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << slow[i] << " ";
        }
    }
    return 0;
}
