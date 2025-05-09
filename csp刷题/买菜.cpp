#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, cnt = 0;
    cin >> n;
    vector<ll> rec(1000006, 0);
    for (ll i = 1; i <= 2 * n; i++)
    {
        ll start;
        ll end;
        cin >> start >> end;
        rec[start + 1]++;
        rec[end + 1]--;
    }
    for (ll i = 1; i <= 1000000; i++)
    {
        rec[i] += rec[i - 1];
        if (rec[i] >= 2)
            cnt++;
    }
    cout << cnt;
    return 0;
}
