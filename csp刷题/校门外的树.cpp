#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll n;
ll a[1005], f[1005], vit[100005];
vector<ll> divisor[100005];
int main()
{
    for (ll i = 1; i <= 100000; i++)
    {
        for (ll j = 2 * i; j <= 100000; j += i)
        {
            divisor[j].push_back(i);
        }
    }
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    f[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        memset(vit, 0, sizeof vit);
        for (ll j = i - 1; j >= 1; j--)
        {
            ll g = a[i] - a[j];
            ll cnt = 0;
            for (auto &tem : divisor[g])
            {
                if (vit[tem] == 0)
                {
                    vit[tem] = 1;
                    cnt++;
                }
            }
            vit[g] = 1;
            f[i] = (f[i] + f[j] * cnt % mod) % mod;
        }
    }
    cout << f[n] << endl;
    return 0;
}
