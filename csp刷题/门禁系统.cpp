#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hash[1005] = {0};
    int n;
    cin >> n;
    vector<int> cnts(n, 0);
    vector<int> result;
    for (auto &x : cnts)
    {
        cin >> x;
        hash[x]++;
        result.push_back(hash[x]);
    }
    for (int i = 0; i < result.size() - 1; i++)
    {
        cout << result[i] << " ";
    }
    cout << result[result.size() - 1];
    return 0;
}