#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 10;
string op[N];
int tem, b[N], n = 0, mx = 1;
double a[N];
long long by[N], sl[N];
int main()
{
    for (int i = 1;; i++)
    {
        if (cin >> op[i])
            n++;
        else
            break; // 说明已经读入全部数据
        if (op[i][0] != 'c')
            cin >> a[i] >> b[i];
        else
        {
            cin >> tem;
            op[tem] = 'd'; // 标记需要delete的位置
        }
    }
    for (int i = 1; i <= n; i++)
    {
        tem = a[i] * 1000 / 10;
        if (op[i][0] == 'b')
            by[tem] += b[i];
        if (op[i][0] == 's')
            sl[tem] += b[i];
    }
    for (int i = 1; i <= N; i++)
    {
        by[i] += by[i - 1];
        sl[i] += sl[i - 1];
    }
    for (int i = 1; i <= N; i++)
    {
        if (min(sl[i], by[N] - by[i - 1]) >= min(sl[mx], by[N] - by[mx - 1]))
            mx = i;
    }
    printf("%.2lf %lld", mx / 100.0, min(sl[mx], by[N] - by[mx - 1]));
    return 0;
}
