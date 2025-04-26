#include <bits/stdc++.h>
using namespace std;
int n, result = -1;
int check(int mid, vector<int> &nums)
{
    int bi = 0, sm = 0;
    for (int j = 0; j < n; j++)
    {
        if (nums[j] > nums[mid])
            bi++;
        if (nums[j] < nums[mid])
            sm++;
    }
    if (bi == sm)
        return 0;
    if (bi > sm)
        return 1;
    return -1;
}
int main()
{
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid, nums) == 0)
        {
            result = nums[mid];
            break;
        }
        else if (check(mid, nums) == 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}
