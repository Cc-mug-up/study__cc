#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to, val;
    edge(int t, int v) : to(t), val(v) {}
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<edge>> grid(n + 1);
    vector<int> mindist(n + 1, INT_MAX);
    vector<bool> isque(n + 1, false);
    vector<int> cnt(n + 1, 0);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({b, c});
    }
    bool flag = false;
    int start = 1;
    int end = n;
    queue<int> que;
    que.push(start);
    mindist[start] = 0;
    isque[start] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        isque[cur] = false;
        for (auto &e : grid[cur])
        {
            if (mindist[cur] + e.val < mindist[e.to])
            {
                mindist[e.to] = mindist[cur] + e.val;
                if (isque[e.to] != true)
                {
                    que.push(e.to);
                    isque[e.to] = true;
                    cnt[e.to]++;
                    if (cnt[e.to] == n)
                    {
                        flag = true;
                        while (!que.empty())
                            que.pop();
                        break;
                    }
                }
            }
        }
    }
    if (flag)
        cout << "circle" << endl;
    else if (mindist[end] == INT_MAX)
        cout << "unconnected" << endl;
    else
        cout << mindist[end] << endl;
    return 0;
}
