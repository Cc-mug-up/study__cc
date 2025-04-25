#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 2; i < n; i++)
    {
        if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i] || nums[i - 1] > nums[i] && nums[i + 1] > nums[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
