#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, cnt = 0, cur = 0;
    cin >> n >> k;
    while (n--)
    {
        int t;
        cin >> t;
        cur += t;
        if (cur >= k)
        {
            cnt++;
            cur = 0;
        }
    }
    if(cur!=0) cnt++;
    cout << cnt << endl;
    return 0;
}
