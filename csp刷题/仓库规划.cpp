#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n + 1, vector<int>(m, 0));
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            int k;
            for (k = 0; k < m; k++)
            {
                if (nums[i][k] >= nums[j][k])
                    break;
            }
            if (k >= m)
            {
                result[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
