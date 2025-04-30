#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, L, r, t, result = 0;
    cin >> n >> L >> r >> t;
    vector<vector<int>> points(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> sums(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> points[i][j];
            sums[i][j] = points[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int starti = max(1, i - r);
            int endi = min(n, i + r);
            int startj = max(1, j - r);
            int endj = min(n, j + r);
            int sum = sums[endi][endj] - sums[endi][startj - 1] -
                      sums[starti - 1][endj] + sums[starti - 1][startj - 1];
            int count = (endi - starti + 1) * (endj - startj + 1);
            double average = 1.0 * sum / count;
            // cout << sum << endl;
            if (average <= t)
            {
                result++;
                // out << i << " " << j << " " << starti
                //      << " " << endi << " " << startj << " "
                //     << endj << " " << average << endl;
            }
        }
    }
    cout << result << endl;
    return 0;
}
