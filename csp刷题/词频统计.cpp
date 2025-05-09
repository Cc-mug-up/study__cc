#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int allcnts[m + 1] = {0};
    int pcnts[m + 1] = {0};
    bool flag[m + 1] = {false};
    while (n--)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int cnt;
            cin >> cnt;
            allcnts[cnt]++;
            if (flag[cnt] == false)
            {
                pcnts[cnt]++;
                flag[cnt] = true;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            flag[i] = false;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << pcnts[i] << " " << allcnts[i] << endl;
    }
    return 0;
}
