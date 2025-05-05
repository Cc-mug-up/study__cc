#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<double> mul(n + 1, 1);
    vector<double> theta(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        double op, num;
        cin >> op >> num;
        if (op == 1)
        {
            mul[i] = mul[i - 1] * num;
            theta[i] = theta[i - 1];
        }
        else
        {
            mul[i] = mul[i - 1];
            theta[i] = theta[i - 1] + num;
        }
    }
    while (m--)
    {
        int start, end;
        cin >> start >> end;
        long double x, y;
        cin >> x >> y;
        x = x * mul[end] / mul[start - 1];
        y = y * mul[end] / mul[start - 1];
        long double tx = x, ty = y;
        x = tx * cos(theta[end] - theta[start - 1]) - ty * sin(theta[end] - theta[start - 1]);
        y = tx * sin(theta[end] - theta[start - 1]) + ty * cos(theta[end] - theta[start - 1]);
        printf("%.3Lf %.3Lf\n", x, y);
    }
    return 0;
}
