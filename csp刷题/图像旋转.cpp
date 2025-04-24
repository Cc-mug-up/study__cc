#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nums[i][j];
        }
    }
    for (int j = m; j >= 1; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}