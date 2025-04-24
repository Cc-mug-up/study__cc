#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> futher(10005, 0);
int n;
ll m;
typedef struct edge
{
    int l, r, val;
} edge;
void ori()
{
    for (int i = 1; i <= n; i++)
    {
        futher[i] = i;
    }
}
int find(int cur)
{
    if (futher[cur] == cur)
        return cur;
    return futher[cur] = find(futher[cur]);
}
void add(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    futher[u] = v;
}
bool issame(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return true;
    return false;
}
static bool cmp(edge a, edge b)
{
    return a.val < b.val;
}
int main()
{
    ll result = 0;
    cin >> n >> m;
    vector<edge> edges;
    for (ll i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    ori();
    for (ll i = 0; i < m; i++)
    {
        if (issame(edges[i].r, edges[i].l))
            continue;
        add(edges[i].l, edges[i].r);
        result += edges[i].val;
    }
    cout << result;
    return 0;
}
