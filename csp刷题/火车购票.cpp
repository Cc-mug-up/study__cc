#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> pos(21, 5);
    int n;
    cin >> n;
    vector<vector<int>> recs(n);
    for (int index = 0; index < n; index++)
    {
        int cur;
        bool flag = false;
        cin >> cur;
        for (int i = 1; i <= 20; i++)
        {
            if (pos[i] >= cur)
            {
                int start = (i - 1) * 5 + (5 - pos[i]);
                for (int j = 1; j <= cur; j++)
                {
                    recs[index].push_back(start + j);
                }
                pos[i] -= cur;
                flag = true;
                if (flag)
                    break;
            }
        }
        if (!flag)
        {
            for (int i = 1; i <= 20; i++)
            {
                if (pos[i] != 0)
                {
                    int d = 0;
                    if (cur >= pos[i])
                        d = pos[i];
                    else
                        d = pos[i] - cur;
                    int start = (i - 1) * 5 + (5 - pos[i]);
                    for (int j = 1; j <= pos[i] && cur > 0; j++, cur--)
                    {
                        recs[index].push_back(start + j);
                    }
                    pos[i] -= d;
                    if (cur == 0)
                        break;
                }
            }
        }
    }
    for (auto &x : recs)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
