#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<bool> isval(n + 1, 0);
    isval[0] = true;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (!isval[y])
            cnt++;
        isval[x] = true;
    }
    cout << cnt << endl;
    return 0;
}
