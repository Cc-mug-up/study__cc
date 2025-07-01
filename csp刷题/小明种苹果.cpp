#include <bits/stdc++.h>
using namespace std;
int all[1005] = {0};
int tsum[1005] = {0};
pair<int, int> m;
int main()
{
    m.first = 1;
    m.second = 0;
    int N, M, ans = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            int t;
            cin >> t;
            if (j == 0)
                all[i] = t;
            else
                tsum[i] -= t;
        }
        if (tsum[i] > m.second)
        {
            m.first = i;
            m.second = tsum[i];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        ans += all[i] - tsum[i];
    }
    cout << ans << " " << m.first << " " << m.second << endl;
    return 0;
}
