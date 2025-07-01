#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10005;
const int D = 25;
ll Q[N][D], K[D][N], V[N][D], W[N];
int n, d;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> Q[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> K[j][i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> V[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> W[i];
    ll first[D][D] = {0}, second[N][D] = {0};
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                first[i][j] += K[i][k] * V[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = 1; k <= d; k++)
            {
                second[i][j] += Q[i][k] * first[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            second[i][j] *= W[i];
            cout << second[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
