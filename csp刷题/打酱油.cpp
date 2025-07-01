#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int dp[N + 1] = {0};
    for (int i = 0; i <= N; i++)
    {
        if (i < 10)
            continue;
        else if (i < 30)
            dp[i] = dp[i - 10] + 1;
        else if (i < 50)
            dp[i] = max({dp[i - 30] + 4, dp[i - 10] + 1});
        else
        {
            dp[i] = max({dp[i - 10] + 1, dp[i - 30] + 4, dp[i - 50] + 7});
        }
    }
    cout << dp[N] << endl;
    return 0;
}
