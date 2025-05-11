#include <bits/stdc++.h>
using namespace std;
int n;
int check(int x, vector<int> nums)
{
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] < x)
            nums[i] = 0;
    }
    int re = 0;
    if (nums[1] != 0)
        re++;
    for (int i = 2; i <= n; i++)
    {
        if (nums[i - 1] == 0 && nums[i] != 0)
            re++;
    } 
    return re;
}
int main()
{
    int ans = 0;
    cin >> n;
    vector<int> nums(n + 1, 0);
    unordered_set<int> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (nums[i] != 0 && se.find(nums[i]) == se.end())
        {
            se.insert(nums[i]);
        }
    }
    bool flag = false;
    for (int i = 2; i < n; i++)
    {
        if (nums[i - 1] != 0 && nums[i] != 0 && nums[i + 1] != 0)
            flag = true;
    }
    if (!flag)
    {
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] != 0)
                ans++;
        }
    }
    else
    {
        for (auto &x : se)
        {
            int tem = check(x, nums);
            ans = max(ans, tem);
        }
    }
    cout << ans << endl;
    return 0;
}
