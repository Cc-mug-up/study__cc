#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    unordered_map<string, int> m;
    cin >> k;
    while (k--)
    {
        string all;
        for (int i = 1; i <= 8; i++)
        {
            string tem;
            cin >> tem;
            all += tem;
        }
        m[all]++;
        cout << m[all] << endl;
    }
    return 0;
}
