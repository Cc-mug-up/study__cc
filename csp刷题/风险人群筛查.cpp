#include <bits/stdc++.h>
using namespace std;
int n, k, t, xl, xb, xr, xu, cnt = 0, result1 = 0, result2 = 0, m;
bool isin(int x, int y)
{
    if (x >= xl && x <= xr && y >= xb && y <= xu)
        return true;
    return false;
}
int main()
{
    cin >> n >> k >> t >> xl >> xb >> xr >> xu;
    while (n--)
    {
        cnt = 0;
        m = 0;
        for (int i = 1; i <= t; i++)
        {
            int x, y;
            cin >> x >> y;
            if (isin(x, y))
            {
                cnt++;
                m = max(cnt, m);
            }
            else
            {
                cnt = 0;
            }
        }
        if (m != 0)
        {
            result1++;
        }
        if (m >= k)
        {
            result2++;
        }
    }
    cout << result1 << endl
         << result2 << endl;
    return 0;
}
