#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll a, ll b, ll p)
{
    ll ans = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a*a % p;
    }
    return ans;
}
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    cout << power(a, b, c) << endl;
    return 0;
}
