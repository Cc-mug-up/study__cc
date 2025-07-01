#include <bits/stdc++.h>
using namespace std;
void smallwhite(string &t)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] >= 'a')
            t[i] -= 32;
    }
}
int main()
{
    int n, m, cnt = 0;
    unordered_set<string> se;
    unordered_set<string> se1;
    unordered_set<string> se2;
    cin >> n >> m;

    while (n--)
    {
        string tem;
        cin >> tem;
        smallwhite(tem);
        se.insert(tem);
        se2.insert(tem);
    }
    while (m--)
    {
        string tem;
        cin >> tem;
        smallwhite(tem);
        if (se.find(tem) != se.end() && se1.find(tem) == se1.end())
            cnt++;
        se1.insert(tem);
        se2.insert(tem);
    }
    cout << cnt << endl
         << se2.size() << endl;
    return 0;
}
