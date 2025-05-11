#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int main()
{
    int n, ans = 0, m = 0;
    cin >> n;
    vector<int> nums(N, 0);
    set<int> se;
    vector<int> rec[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        rec[nums[i]].push_back(i);
        se.insert(nums[i]);
        if (!nums[i - 1] && nums[i])
            ans++;
    }
    for (auto &s : se)
    {
        for (auto &cur : rec[s])
        {
            if (nums[cur - 1] && nums[cur + 1] && nums[cur])
                ans++;
            if (!nums[cur - 1] && !nums[cur + 1] && nums[cur])
                ans--;
            nums[cur] = 0;
        }
        m = max(m, ans);
    }
    cout << m << endl;
    return 0;
}
