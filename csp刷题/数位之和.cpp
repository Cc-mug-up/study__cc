#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int ans = 0;
    cin >> n;
    while (n)
    {
        int b = n % 10;
        ans += b;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}
