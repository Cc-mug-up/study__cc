#include <bits/stdc++.h>
using namespace std;
int futher[1005];
int n;
pair<int, int> result;
vector<pair<int, int>> edges;
vector<int> agrees(1005, 0);
vector<pair<int, int>> deleteedges;
//****************************
// ���鼯����
void ori()
{
    // ��ʼ�� ÿ��������� �Լ�
    for (int i = 1; i <= n; i++)
    {
        futher[i] = i;
    }
}
int find(int cur)
{
    // ѹ��·���� -> ��������
    if (futher[cur] == cur)
        return cur;
    return futher[cur] = find(futher[cur]);
}
void add(int u, int v)
{
    // ��� �������Ϊһ������ /����Ѿ�Ϊһ������������� ����
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    futher[u] = v;
}
bool issame(int u, int v)
{
    // ��� ��������Ƿ��Ѿ���һ��������
    u = find(u);
    v = find(v);
    if (u == v)
        return true;
    return false;
}
//*****************************
bool afterdeleteistree(pair<int, int> del)
{
    // ��ɾ���˵������Ϊ2�ıߺ� ���ͼ�Ƿ񹹳���һ��������
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
    // �ų������Ϊ2����������ͼ�Ƿ���һ�������޻�ͼ
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
        // ��ӱ� + ��¼���
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        agrees[v]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // ����������Ϊ2�ı߽�� ��¼������
        if (agrees[edges[i].second] == 2)
            deleteedges.push_back({edges[i].first, edges[i].second});
    }
    if (deleteedges.size() > 0)
    {
        // �����Ϊ2�ĵ� ���μ�� �鿴ɾ�������ߺ��Ƿ��ܹ���һ��������
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
        // �����Ϊ2�Ľ�� ���ɾ�������ߺ� -> �γ������޻�ͼ
        getedge();
    }
    cout << result.first << " " << result.second;
    // ���ش�
    return 0;
}
