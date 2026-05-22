#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (ll i = 1; i < n; i++)
    {
        if (nums[i] + nums[i - 1] > k)
        {
            if (nums[i - 1] >= k)
            {
                ans += nums[i - 1] - k;
                nums[i - 1] = k;
                ans += nums[i];
                nums[i] = 0;
            }
            else if (nums[i] >= k)
            {
                ll t = k - nums[i - 1];
                ans += nums[i] - t;
                nums[i] = t;
            }
            else if (nums[i - 1] < k)
            {
                ll t = nums[i - 1] + nums[i] - k;
                ans += t;
                nums[i] -= t;
            }
        }
    }
    cout << ans << endl;
    return 0;
}