#include <bits/stdc++.h>
using namespace std;
char p[14][5];
int re[13];
int inde = 1;
int kcnt = 0;
int an = 0;
int con(char cur)
{
    if (cur == 'A')
        return 1;
    if (cur == '0')
        return 10;
    if (cur == 'J')
        return 11;
    if (cur == 'Q')
        return 12;
    if (cur == 'K')
        return 13;
    else
        return cur - '0';
}
char op(char cur)
{
    int t = con(cur);
    // cout << t << endl;
    char ans = p[t][4];
    for (int i = 4; i >= 2; i--)
    {
        p[t][i] = p[t][i - 1];
    }
    re[t]++;
    p[t][1] = cur;
    return ans;
}
void run1(char cur)
{
    while (true)
    {
        // cout << cur << endl;
        if (cur == 'K')
        {
            kcnt++;
            break;
        }
        cur = op(cur);
    }
}
void run()
{
    while (true)
    {
        if (kcnt == 4 || inde > 4)
            break;
        char cur = p[13][inde++];
        if (cur == 'K')
        {
            kcnt++;
            continue;
        }
        run1(cur);
    }
}
int main()
{
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> p[i][j];
        }
    }
    run();
    for (int i = 1; i <= 12; i++)
    {
        if (re[i] == 4)
            an++;
    }
    // cout << 11111;
    cout << an << endl;
    return 0;
}