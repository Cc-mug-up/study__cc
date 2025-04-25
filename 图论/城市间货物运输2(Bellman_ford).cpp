#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> mindist(n + 1, INT_MAX);
    vector<vector<int>> grid;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid.push_back({a, b, c});
    }
    int start = 1;
    int end = n;
    bool flag = false;
    mindist[start] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (auto &cur : grid)
        {
            int from = cur[0];
            int to = cur[1];
            int val = cur[2];
            if (i < n)
            {
                if (mindist[from] != INT_MAX && mindist[from] + val < mindist[to])
                    mindist[to] = mindist[from] + val;
            }
            else
            {
                if (mindist[from] != INT_MAX && mindist[from] + val < mindist[to])
                    flag = true;
            }
        }
    }
    if (flag)
        cout << "circle" << endl;
    else if (mindist[end] != INT_MAX)
        cout << mindist[end] << endl;
    else
        cout << "unconnected" << endl;
    return 0;
}
