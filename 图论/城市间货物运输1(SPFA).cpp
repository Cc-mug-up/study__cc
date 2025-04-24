#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to, val;
    edge(int to, int val)
    {
        this->to = to;
        this->val = val;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<edge>> grid(n + 1);
    vector<bool> isque(n + 1, false);
    vector<int> mindist(n + 1, INT_MAX);
    queue<int> que;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a].push_back({b, c});
    }
    int start = 1;
    int end = n;
    que.push(start);
    mindist[start] = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        isque[cur] = false;
        for (auto &cedge : grid[cur])
        {
            if (mindist[cur] + cedge.val < mindist[cedge.to])
            {
                mindist[cedge.to] = mindist[cur] + cedge.val;
                if (isque[cedge.to] == false)
                {
                    que.push(cedge.to);
                    isque[cedge.to] = true;
                }
            }
        }
    }
    if (mindist[end] == INT_MAX)
        cout << "unconnected" << endl;
    else
        cout << mindist[end] << endl;
    return 0;
}
