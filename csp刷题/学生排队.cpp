#include <bits/stdc++.h>
using namespace std;
int n, k;
int sno2pos[1005];
int pos2sno[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sno2pos[i] = i;
        pos2sno[i] = i;
    }
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (b != 0)
        {
            int sno2, pos2;
            int end = abs(b);
            int move = (b > 0) ? 1 : -1;
            int pos1 = sno2pos[a];
            for (int i = 1; i <= end; i++)
            {
                sno2 = pos2sno[pos1 + move];
                pos2 = sno2pos[sno2];
                pos2sno[pos1] = sno2;
                sno2pos[sno2] = pos1;
                pos1 = pos2;
            }
            pos2sno[pos2] = a;
            sno2pos[a] += b;
        }
    }
    cout << pos2sno[1];
    for (int i = 2; i <= n; i++)
    {
        cout << " " << pos2sno[i];
    }
    return 0;
}
