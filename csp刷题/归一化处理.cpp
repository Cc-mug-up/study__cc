#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, sum = 0;
    cin >> n;
    vector<double> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    double avg = sum / n;
    double dif = 0;
    for (int i = 1; i <= n; i++)
    {
        dif += pow(nums[i] - avg, 2);
    }
    dif /= n;
    dif = sqrt(dif);
    for (int i = 1; i <= n; i++)
    {
        printf("%.16f\n", (nums[i] - avg) / dif);
    }
    return 0;
}
