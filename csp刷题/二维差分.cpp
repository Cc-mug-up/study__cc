#include <bits/stdc++.h>
using namespace std;
int nums[10005][10005];
int d[10005][10005];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nums[i][j];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        d[x1][y1] += c;
        d[x1][y2 + 1] -= c;
        d[x2 + 1][y1] -= c;
        d[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            nums[i][j] += d[i][j];
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
