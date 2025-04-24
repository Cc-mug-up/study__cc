#include <bits/stdc++.h>
using namespace std;
int futher[1005];
int n;
pair<int, int> result;
vector<pair<int, int>> edges;
vector<int> agrees(1005, 0);
vector<pair<int, int>> deleteedges;
//****************************
// 并查集函数
void ori()
{
    // 初始化 每个点的祖先 自己
    for (int i = 1; i <= n; i++)
    {
        futher[i] = i;
    }
}
int find(int cur)
{
    // 压缩路径法 -> 查找祖先
    if (futher[cur] == cur)
        return cur;
    return futher[cur] = find(futher[cur]);
}
void add(int u, int v)
{
    // 添加 两个结点为一个集合 /如果已经为一个集合里的内容 返回
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    futher[u] = v;
}
bool issame(int u, int v)
{
    // 检查 两个结点是否已经在一个集合里
    u = find(u);
    v = find(v);
    if (u == v)
        return true;
    return false;
}
//*****************************
bool afterdeleteistree(pair<int, int> del)
{
    // 在删除了导致入度为2的边后 这个图是否构成了一个有向树
    ori();
    for (int i = 0; i <= n - 1; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        if (u == del.first && v == del.second)
            continue;
        if (issame(u, v))
        {
            return false;
        }
        add(u, v);
    }
    return true;
}
void getedge()
{
    // 排除了入读为2的情况，检查图是否是一个有向无环图
    ori();
    for (int i = 0; i <= n - 1; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        if (issame(u, v))
        {
            result = {u, v};
            return;
        }
        add(u, v);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        // 添加边 + 记录入度
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        agrees[v]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // 倒叙查找入度为2的边结点 记录这条边
        if (agrees[edges[i].second] == 2)
            deleteedges.push_back({edges[i].first, edges[i].second});
    }
    if (deleteedges.size() > 0)
    {
        // 有入度为2的点 依次检查 查看删掉这条边后是否能构成一个有向树
        if (afterdeleteistree(deleteedges[0]))
        {
            result = {deleteedges[0].first, deleteedges[0].second};
        }
        else
        {
            result = {deleteedges[1].first, deleteedges[1].second};
        }
    }
    else
    {
        // 无入度为2的结点 检查删掉那条边后 -> 形成有向无环图
        getedge();
    }
    cout << result.first << " " << result.second;
    // 返回答案
    return 0;
}
