#include <bits/stdc++.h>
using namespace std;
int n, m, result = 0;
int f[1005];
void ori()
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}
int findf(int a)
{
    if (f[a] == a)
        return a;
    return f[a] = findf(f[a]);
}
void add(int a, int b)
{
    a = findf(a);
    b = findf(b);
    if (a == b)
        return;
    f[a] = b;
}
bool issame(int a, int b)
{
    a = findf(a);
    b = findf(b);
    if (a == b)
        return true;
    return false;
}
struct Node
{
    int start;
    int end;
    int fee;
    Node(int e, int s, int f) : start(s), end(e), fee(f) {}
};
vector<Node> nodes;
static bool cmp(Node &a, Node &b)
{
    return a.fee < b.fee;
}
int main()
{
    cin >> n >> m;
    ori();
    while (m--)
    {
        int s, e, f;
        cin >> s >> e >> f;
        Node node(s, e, f);
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    for (auto &node : nodes)
    {
        if (issame(node.start, node.end))
            continue;
        add(node.start, node.end);
        result += node.fee;
    }
    cout << result;
    return 0;
}
