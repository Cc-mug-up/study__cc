#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int futher[1005];
bool ral[1005][1005];
void ori()
{
    for (int i = 1; i <= n; i++)
    {
        futher[i] = i;
    }
}
int find(int cur)
{
    if (futher[cur] == cur)
        return cur;
    return futher[cur] = find(futher[cur]);
}
void add(int a, int b)
{
    int af = find(a);
    int bf = find(b);
    if (af != bf)
    {
        futher[af] = bf;
    }
    return;
}
int main()
{
    pair<int, int> result;
    cin >> n;
    ori();
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            result = {a, b};
        add(a, b);
    }
    cout << result.first << " " << result.second;
    return 0;
}