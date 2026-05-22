#include <bits/stdc++.h>
using namespace std;
string str;
int k, i;
int main()
{
    cin >> str;
    cin >> k;
    while (k)
    {
        for (i = 0; str[i] <= str[i + 1]; i++)
            ;
        str.erase(i, 1);
        k--;
    }
    while (str[0] == '0')
    {
        str.erase(0, 1);
    }
    if(str=="") str="0";
    cout << str << endl;
    return 0;
}