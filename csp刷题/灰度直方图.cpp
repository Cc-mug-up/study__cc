#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, L;
    cin >> n >> m >> L;
    int cnt[300] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tem;
            cin >> tem;
            cnt[tem]++;
        }
    }
    for (int i = 0; i < L; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
