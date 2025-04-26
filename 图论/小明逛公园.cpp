#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a][b][0] = c;
        grid[b][a][0] = c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (grid[a][b][n] == 10005)
            cout << -1 << endl;
        else
            cout << grid[a][b][n] << endl;
    }
    return 0;
}
