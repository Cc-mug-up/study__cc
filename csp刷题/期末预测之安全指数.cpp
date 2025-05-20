#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        res+=a*b;
    }
    if(res<=0) cout<<0<<endl;
    else cout<<res;
    return 0;
}
