#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 10005));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a][b] = c;
        grid[b][a] = c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (grid[a][b] == 10005)
            cout << -1 << endl;
        else
            cout << grid[a][b] << endl;
    }
    return 0;
}
