#include <bits/stdc++.h>
using namespace std;
int n;
int cnts[5] = {0};
set<pair<int, int>> se;
bool check(pair<int, int> node)
{
    int x = node.first, y = node.second;
    if (se.find({x - 1, y}) != se.end() && se.find({x, y - 1}) != se.end() && se.find({x + 1, y}) != se.end() && se.find({x, y + 1}) != se.end())
        return true;
    return false;
}
int count(pair<int, int> node)
{
    int c = 0;
    int x = node.first, y = node.second;
    if (se.find({x - 1, y - 1}) != se.end())
        c++;
    if (se.find({x + 1, y - 1}) != se.end())
        c++;
    if (se.find({x - 1, y + 1}) != se.end())
        c++;
    if (se.find({x + 1, y + 1}) != se.end())
        c++;
    return c;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        se.insert({x, y});
    }
    for (auto node : se)
    {
        if (!check(node))
            continue;
        cnts[count(node)]++;
    }
    for (int i = 0; i <= 4; i++)
    {
        cout << cnts[i] << endl;
    }
    return 0;
}
