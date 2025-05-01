#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> c(n + 1, 1);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];
    }
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = (m % c[i] - pre) / c[i - 1];
        pre = m % c[i];
    }
    for (int i = 1; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << b[n] << endl;
    return 0;
}
