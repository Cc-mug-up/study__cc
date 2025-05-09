#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> firstday(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> firstday[i];
    }

    vector<int> secondday(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int sum = firstday[i - 1] + firstday[i] + firstday[i + 1];
        secondday[i] = sum / 3;
    }
    secondday[1] = (firstday[1] + firstday[2]) / 2;
    secondday[n] = (firstday[n - 1] + firstday[n]) / 2;
    for (int i = 1; i < n; i++)
    {
        cout << secondday[i] << " ";
    }
    cout << secondday[n];
    return 0;
}
