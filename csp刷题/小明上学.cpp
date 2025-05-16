#include <bits/stdc++.h>
using namespace std;
int main()
{
    int red, yellow, green, n, alltime = 0;
    cin >> red >> yellow >> green;
    cin >> n;
    while (n--)
    {
        int k, t;
        cin >> k >> t;
        if (k == 0)
            alltime += t;
        else if (k == 1)
            alltime += t;
        else if (k == 2)
            alltime += t + red;
    }
    cout << alltime << endl;
    return 0;
}
