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
    /*cout << "����ǰ�����У�" << endl;
    nums.show();
    nums.sort();
    cout << "���������У�" << endl;
    nums.show();
    int index;
    cout << "����Ҫ��ѯ�����±꣺" << endl;
    cin >> index;
    cout << nums.getindex(index) << endl;
    int val;
    cout << "����Ҫ��ѯ�������ݣ�" << endl;
    cin >> val;
    cout << nums.find(val) << endl;*/
    nums.push_back(100);
    nums.show();
    cout << endl;
    nums.pop();
    nums.show();
    return 0;
}
