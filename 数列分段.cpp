#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=1,n;
    cin>>n;
    vector<int> nums(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    for(int i=2;i<=n;i++){
        if(nums[i]!=nums[i-1]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
