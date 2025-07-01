#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, cnt1 = 0, cnt2 = 0;
bool isdiao[1005] = {false};
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m, cur = 0;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int t;
            cin >> t;
            if (j == 1)
                cur = t;
            else
            {
                if (t > 0)
                {
                    if (cur != t)
                    {
                        isdiao[i] = true;
                        cur = t;
                    }
                }
                else
                {
                    cur += t;
                }
            }
        }
        sum += cur;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isdiao[i])
            cnt1++;
        bool a, b, c;
        b = isdiao[i];
        if (i == 1)
            a = isdiao[n];
        else
            a = isdiao[i - 1];
        if (i == n)
            c = isdiao[1];
        else
            c = isdiao[i + 1];
        if (a && b && c)
            cnt2++;
    }
    cout << sum << " " << cnt1 << " " << cnt2 << endl;
    return 0;
}
