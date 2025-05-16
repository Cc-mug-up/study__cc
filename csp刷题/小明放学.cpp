#include <bits/stdc++.h>
using namespace std;
int main()
{
    int red, yellow, green;
    cin >> red >> yellow >> green;
    int n, sum = red + yellow + green;
    long long alltime = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k, t;
        cin >> k >> t;
        if (k == 0)
            alltime += t;
        else
        {
            int c;
            if (k == 1)
                c = (red - t + alltime) % sum;
            else if (k == 2)
                c = (sum - t + alltime) % sum;
            else if (k == 3)
                c = (red + green - t + alltime) % sum;
            if (c < red)
                alltime += red - c;
            else if (c >= green + red)
                alltime += sum - c + red;
        }
    }
    cout << alltime << endl;
    return 0;
}
