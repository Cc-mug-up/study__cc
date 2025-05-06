#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> se;
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    while (n--)
    {
        int t;
        cin >> t;
        sum1 += t;
        if (se.find(t) == se.end())
            sum2 += t;
        se.insert(t);
    }
    cout << sum1 << endl
         << sum2;
    return 0;
}
