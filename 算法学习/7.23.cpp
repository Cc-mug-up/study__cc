#include <bits/stdc++.h>
using namespace std;
using ll = long long;
priority_queue<int> que;
int main()
{
    ll n, ans = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        que.push(-t);
    }
    if (n == 1)
    {
        cout << que.top() << endl;
        return 0;
    }
    while (true)
    {
        ll a, b;
        a = -que.top();
        que.pop();
        b = -que.top();
        que.pop();
        // cout << a << " " << b << endl;
        ans += a + b;
        if (que.empty())
            break;
        que.push(-(a + b));
    }
    cout << ans << endl;
    return 0;
}