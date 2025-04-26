#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, result = -1;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int bi = 0, sm = 0;
        for (int j = 1; j <= n; j++)
        {
            if (nums[j] > nums[i])
                bi++;
            if (nums[j] < nums[i])
                sm++;
        }
        if (bi == sm)
            result = nums[i];
    }
    cout << result;
    return 0;
}
