#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node
{
    ll t;
    ll c;
    Node(ll t, ll c) : t(t), c(c) {}
    bool operator<(const Node &other) const
    {
        if (t == other.t)
            return c < other.c;
        return t < other.t;
    }
};
int main()
{
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    priority_queue<Node> q;
    while (n--)
    {
        ll t, c;
        cin >> t >> c;
        Node node(t, c);
        q.push(node);
    }
    while (!q.empty() && m > 0)
    {
        Node cur = q.top();
        q.pop();
        if (m >= cur.c)
        {
            cur.t -= 1;
            m -= cur.c;
        }
        if(cur.t!=0)q.push(cur);
    }
    ans = q.top().t;
    if (ans < k)
        cout << k;
    else
        cout << ans;
    return 0;
}
