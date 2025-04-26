#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to, val;
    edge(int t, int v) : to(t), val(v) {}
};
int main()
{
    int n, m, src, dst, k;
    cin >> n >> m;
    vector<list<edge>> grid(n + 1);
    vector<int> mindist(n + 1, INT_MAX);
    vector<int> mindist_copy(n + 1, INT_MAX);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({b, c});
    }
    cin >> src >> dst >> k;
    k++;
    queue<int> que;
    que.push(src);
    mindist[src] = 0;
    while (!que.empty() && k--)
    {
        int que_size = que.size();
        mindist_copy = mindist;
        vector<bool> isque(n + 1, false);
        while (que_size--)
        {
            int cur = que.front();
            que.pop();
            // isque[cur] = false;
            for (auto &e : grid[cur])
            {
                if (mindist_copy[cur] + e.val < mindist[e.to])
                {
                    mindist[e.to] = mindist_copy[cur] + e.val;
                    if (isque[e.to] == false)
                    {
                        que.push(e.to);
                        isque[e.to] = true;
                    }
                }
            }
        }
    }
    if (mindist[dst] == INT_MAX)
        cout << "unreachable" << endl;
    else
        cout << mindist[dst] << endl;
    return 0;
}
