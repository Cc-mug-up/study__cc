#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
int m[N];
int main()
{
    int n,total,k,maxx=0;
    cin>>n>>total>>k;
    while(n--){
        int t,c;
        cin>>t>>c;
        m[t]+=c;
        maxx=max(maxx,t);
    }
    for(int i=maxx;i>=k;i--){
        if(total<m[i]){
            cout<<i;
            return 0;
        }
        total-=m[i];
        m[i-1]+=m[i];
    }
    cout<<k;
    return 0;
}
