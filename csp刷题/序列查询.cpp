#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, N;
    cin >> n >> N;
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    int cur = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i >= nums[cur + 1] && cur < n)
            cur++;
        sum += cur;
    }
    cout << sum << endl;
    return 0;
}