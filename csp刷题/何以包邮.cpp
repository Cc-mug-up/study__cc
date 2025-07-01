#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 35, M = 3e5 + 10;
int w[N];
bool f[M];
int n, x;

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    f[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = M; j >= w[i]; j--)
            f[j] |= f[j - w[i]];

    for (int i = x; i <= M; i++)
        if (f[i])
        {
            cout << i;
            break;
        }

    return 0;
}