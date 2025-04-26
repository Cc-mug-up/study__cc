#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    int rec = 0;
    for (int i = 2; i <= n; i++)
    {
        rec = max(abs(nums[i] - nums[i - 1]), rec);
    }
    cout << rec << endl;
    return 0;
}
