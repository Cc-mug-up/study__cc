#include <bits/stdc++.h>
using namespace std;
int d[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, -1, -2, 1};
int grid[1005][1005];
int b1, b2;
struct Knight
{
    int f, g, h;
    int x, y;
    bool operator<(const Knight &k) const
    {
        return k.f < f;
    }
};
int dis(Knight &k)
{
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}
void Astar(Knight &k)
{
    priority_queue<Knight> que;
    que.push(k);
    while (!que.empty())
    {
        Knight cur = que.top();
        if (cur.x == b1 && cur.y == b2)
            break;
        Knight next;
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            next.x = cur.x + d[i][0];
            next.y = cur.y + d[i][1];
            if (next.x >= 1 && next.x <= 1000 && next.y >= 1 && next.y <= 1000)
            {
                if (grid[next.x][next.y] != 0)
                    continue;
                grid[next.x][next.y] = grid[cur.x][cur.y] + 1;
                next.g = cur.g + 5;
                next.h = dis(next);
                next.f = next.g + next.h;
                que.push(next);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(grid, 0, sizeof(grid));
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Knight k;
        k.x = x1;
        k.y = y1;
        b1 = x2;
        b2 = y2;
        k.g = 0;
        k.h = dis(k);
        k.f = k.g + k.h;
        Astar(k);
        cout << grid[b1][b2] << endl;
    }
    return 0;
}
