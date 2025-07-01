#include <bits/stdc++.h>
using namespace std;
struct node
{
    int index;
    double dis;
};
static bool cmp(node a, node b)
{
    if (a.dis == b.dis)
        return a.index < b.index;
    return a.dis < b.dis;
}
int main()
{
    int n, X, Y;
    vector<node> nodes;
    cin >> n >> X >> Y;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        node ne;
        ne.index = i;
        ne.dis = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        nodes.push_back(ne);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    int cnt = 0;
    for (auto &cur : nodes)
    {
        cnt++;
        cout << cur.index << endl;
        if (cnt == 3)
            break;
    }
    return 0;
}
