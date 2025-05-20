#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    ll n;
    int iszero[100005] = {0}, isone[100005] = {0};
    cin >> n;
    vector<pair<ll, ll>> pairs;
    set<ll> se;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        pairs.push_back({a, b});
        se.insert(a);
    }
    sort(pairs.begin(), pairs.end(), cmp);
    if (pairs[0].second == 0)
        iszero[0] = 1;
    else
        isone[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        if (pairs[i].second == 0)
        {
            iszero[i] = iszero[i - 1] + 1;
            isone[i] = isone[i - 1];
        }
        else
        {
            isone[i] = isone[i - 1] + 1;
            iszero[i] = iszero[i - 1];
        }
    }
    ll cur = pairs[0].first;
    ll sum = 0;
    ll ans = 0;
    sum = isone[n - 1];
    ans = pairs[0].first;
    for (ll i = 1; i < n; i++)
    {
        if (pairs[i].first != cur)
        {
            ll tem = iszero[i - 1] + isone[n - 1] - isone[i - 1];
            cur = pairs[i].first;
            if (sum <= tem)
            {
                sum = tem;
                ans = pairs[i].first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
