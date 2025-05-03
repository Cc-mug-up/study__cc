#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int dx = 0, dy = 0;
    while (n--)
    {
        int tx, ty;
        cin >> tx >> ty;
        dx += tx;
        dy += ty;
    }
    while (m--)
    {
        int endx, endy;
        cin >> endx >> endy;
        endx += dx;
        endy += dy;
        cout << endx << " " << endy << endl;
    }
    return 0;
}
