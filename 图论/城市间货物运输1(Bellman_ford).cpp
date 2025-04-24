#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    vector<int> mindist(n+1,INT_MAX);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        grid.push_back({a,b,c});
    }
    int start=1;
    int end=n;
    mindist[start]=0;
    for(int i=0;i<n-1;i++){
        for(auto &ride:grid){
            int from=ride[0];
            int to=ride[1];
            int val=ride[2];
            if(mindist[from]!=INT_MAX && mindist[from]+val<mindist[to]){
                mindist[to]=mindist[from]+val;
            }
        }
    }
    if(mindist[n]!=INT_MAX) cout<<mindist[n]<<endl;
    else cout<<"unconnected"<<endl;
    return 0;
}
