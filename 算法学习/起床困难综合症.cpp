#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> nums;
int n, m;
int cal(int bit, int cur)
{
    for (auto &num : nums)
    {
        int x = num.second >> bit & 1;
        if (num.first == "AND")
            cur &= x;
        else if (num.first == "OR")
            cur |= x;
        else
            cur ^= x;
    }
    return cur;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        int val;
        cin >> str >> val;
        nums.push_back({str, val});
    }
    int val = 0, ans = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int re0 = cal(bit, 0);
        int re1 = cal(bit, 1);
        if (val + (1 << bit) <= m && re0 < re1)
            val += (1 << bit), ans += (re1 << bit);
        else
            ans += (re0 << bit);
    }
    cout << ans << endl;
    return 0;
}
