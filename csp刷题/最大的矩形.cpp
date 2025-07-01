#include <bits/stdc++.h>
using namespace std;
int h[1005];
int m[1005][1005];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        m[i][i] = h[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m[i][j] = min(m[i][j - 1], m[j][j]);
            ans = max(ans, (j - i + 1) * m[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
