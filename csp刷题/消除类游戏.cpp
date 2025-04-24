#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n + 2, vector<int>(m + 2, -1));
    vector<vector<bool>> candel(n + 2, vector<bool>(m + 2, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nums[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cur = nums[i][j];
            if (nums[i][j] == nums[i - 1][j] && nums[i][j] == nums[i + 1][j])
            {
                candel[i][j] = true;
                candel[i + 1][j] = true;
                candel[i - 1][j] = true;
            }
            if (nums[i][j] == nums[i][j - 1] && nums[i][j] == nums[i][j + 1])
            {
                candel[i][j] = true;
                candel[i][j - 1] = true;
                candel[i][j + 1] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (candel[i][j])
                nums[i][j] = 0;
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
