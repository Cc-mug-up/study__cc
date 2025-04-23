#include <bits/stdc++.h>
using namespace std;
bool flags[105][105] = {false};
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1 + 1; i <= x2; i++)
        {
            for (int j = y1 + 1; j <= y2; j++)
            {
                flags[i][j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (flags[i][j])
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}