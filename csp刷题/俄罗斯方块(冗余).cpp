#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> nums(16, vector<int>(11, 0));
    vector<vector<bool>> obnums(16, vector<bool>(11, true));
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> nums[i][j];
            if (obnums[i - 1][j] == false || nums[i][j] == 1)
                obnums[i][j] = false;
        }
    }
    vector<vector<int>> pattern(5, vector<int>(5));
    int up = -1, down = 5;
    int left = 5, right = -1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> pattern[i][j];
            if (pattern[i][j] == 1)
            {
                up = max(up, i);
                down = min(down, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    int d = up - down + 1;
    int index;
    cin >> index;
    for (int i = 15 - d + 1; i >= 1; i--)
    {
        bool flag = true;
        for (int k = i; k <= i + d - 1 && flag; k++)
        {
            for (int j = index; j < index + 4 && flag; j++)
            {
                if (nums[k][j] == 1 && pattern[k - i + down][j - index + 1] == 1)
                    flag = false;
            }
        }
        bool obflag = true;
        for (int p = i; p <= i + d - 1; p++)
            for (int l = left; l <= right; l++)
            {
                if (!obnums[p][l + index - 1] && nums[p][l + index - 1] == 0)
                    obflag = false;
            }
        // if (obflag == false)
        //    cout << i << endl;
        if (flag == true && obflag == true)
        {
            for (int k = i; k <= i + d - 1; k++)
            {
                for (int j = index; j < index + 4; j++)
                {

                    if (nums[k][j] == 0)
                    {
                        nums[k][j] = pattern[k - i + down][j - index + 1];
                        //  cout << k << " " << j << " " << k - i + down << " " << j - index + 1 << endl;
                    }
                }
            }
            break;
        }
    }
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
