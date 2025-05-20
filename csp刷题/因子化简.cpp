#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll d, k;
        vector<pair<ll, ll>> d_e;
        cin >> d >> k;
        ll o = d;
        for (ll i = 2; i <= d / i; i++)
        {
            int e = 0;
            while (d % i == 0)
            {
                d /= i;
                e++;
            }
            if (e > 0)
                d_e.push_back({i, e});
        }
        ll ans = 1;
        for (auto &x : d_e)
        {
            if (x.second >= k)
                ans *= pow(x.first, x.second);
        }
        cout << ans << endl;
    }
    return 0;
}
