#include <bits/stdc++.h>
#include "smartvector.h"
// #include "smartvector.tcc"
using namespace std;
int main()
{

    int n;
    cin >> n;
    smartvector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    /*cout << "排序前的数列：" << endl;
    nums.show();
    nums.sort();
    cout << "排序后的数列：" << endl;
    nums.show();
    int index;
    cout << "输入要查询数的下标：" << endl;
    cin >> index;
    cout << nums.getindex(index) << endl;
    int val;
    cout << "输入要查询数的内容：" << endl;
    cin >> val;
    cout << nums.find(val) << endl;*/
    nums.push_back(100);
    nums.show();
    cout << endl;
    nums.pop();
    nums.show();
    return 0;
}
