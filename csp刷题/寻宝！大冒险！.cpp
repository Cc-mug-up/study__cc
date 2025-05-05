#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, L, S;
    set<pair<ll, ll>> se;
    cin >> n >> L >> S;
    vector<vector<ll>> m(S + 1, vector<ll>(S + 1));
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        se.insert({x, y});
    }
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            cin >> m[i][j];
        }
    }
    int cnt = 0;
    for (auto &x : se)
    {
        if (L - x.first < S || L - x.second < S)
            continue;
        bool flag = true;
        for (int i = 0; i <= S; i++)
        {
            for (int j = 0; j <= S; j++)
            {
                if (m[i][j] == 1)
                {
                    if (se.find({x.first + i, x.second + j}) == se.end())
                        flag = false;
                }
                else
                {
                    if (se.find({x.first + i, x.second + j}) != se.end())
                        flag = false;
                }
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
