#include <bits/stdc++.h>
using namespace std;
bool isincludseven(int t)
{
    if (t % 7 == 0)
        return true;
    string tem = to_string(t);
    for (int i = 0; i < tem.size(); i++)
    {
        if (tem[i] == '7')
            return true;
    }
    return false;
}
int main()
{
    int num = 1, cnt = 0, n, per[4] = {0}, cur = 0;
    cin >> n;
    while (true)
    {
        // cout << num << endl;
        if (isincludseven(num))
            per[cur]++;
        else
            cnt++;
        if (cur == 3)
            cur = 0;
        else
            cur++;
        if (cnt == n)
            break;
        num++;
    }
    for (int i = 0; i <= 3; i++)
    {
        cout << per[i] << endl;
    }
    return 0;
}
