#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    vector<int> mindist(n + 1, INT_MAX);
    vector<int> mindist_copy(n + 1, INT_MAX);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid.push_back({a, b, c});
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    mindist[src] = 0;
    for (int i = 1; i <= k + 1; i++)
    {
        mindist_copy = mindist;
        for (auto e : grid)
        {
            int from = e[0];
            int to = e[1];
            int val = e[2];
            if (mindist_copy[from] != INT_MAX && mindist_copy[from] + val < mindist[to])
            {
                mindist[to] = mindist_copy[from] + val;
            }
        }
    }
    if (mindist[dst] == INT_MAX)
        cout << "unreachable" << endl;
    else
        cout << mindist[dst] << endl;
    return 0;
}
