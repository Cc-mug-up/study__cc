#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T MAX(T a, T b)
{
    if (a < b)
        return b;
    else
        return a;
}
int main()
{
    int a = 1, b = 2;
    cout << a << " and " << b << endl
         << "MAX:" << MAX(a, b) << endl;
    double a1 = 1.7, b1 = 2.5;
    cout << a1 << " and " << b1 << endl
         << "MAX:" << MAX(a1, b1) << endl;
    string a2 = "Hello", b2 = "World";
    cout << a2 << " and " << b2 << endl
         << "MAX:" << MAX(a2, b2) << endl;
    return 0;
}
