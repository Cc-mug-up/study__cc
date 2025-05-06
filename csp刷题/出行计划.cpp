#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, m, k;
    ll cha[200005] = {0};
    cin >> n >> m >> k;
    vector<ll> t;
    while (n--)
    {
        ll t, c;
        cin >> t >> c;
        ll left = max((ll)0, t - c - k + 1);
        ll right = max((ll)0, t - k);
        cha[left]++;
        cha[right + 1]--;
    }
    for (ll i = 1; i <= 200000; i++)
    {
        cha[i] += cha[i - 1];
    }
    while (m--)
    {
        ll T;
        cin >> T;
        ll cnt = 0;
        cnt += cha[T];
        cout << cnt << endl;
    }
    return 0;
}
