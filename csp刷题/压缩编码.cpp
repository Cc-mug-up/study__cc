#include <bits/stdc++.h>
using namespace std;
#define N 1005
int f[N][N];
int sums[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sums[i] = sums[i - 1] + a;
    }
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r] = INT_MAX;
            for (int i = l; i <= r; i++)
            {
                f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r] + sums[r] - sums[l - 1]);
            }
        }
    cout << f[1][n] << endl;
    return 0;
}
