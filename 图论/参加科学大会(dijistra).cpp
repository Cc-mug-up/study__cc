#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> vits(n+1,false);
    vector<int> mindist(n+1,INT_MAX);
    vector<vector<int>> stopdist(n+1,vector<int>(n+1,-1));
    vector<int> rates(n+1,-1);
    while(m--){
        int s,e,v;
        cin>>s>>e>>v;
        stopdist[s][e]=v;
    }
    int start=1;
    int end=n;
    mindist[start]=0;
    for(int i=1;i<=n;i++){
        int minval=INT_MAX;
        int index=1;
        for(int i=1;i<=n;i++){
            if(minval>mindist[i]&&!vits[i]){
                index=i;
                minval=mindist[i];
            }
        }
        vits[index]=true;
        for(int i=1;i<=n;i++){
            if(!vits[i]&&stopdist[index][i]>=0&&mindist[index]+stopdist[index][i]<mindist[i]){
                mindist[i]=mindist[index]+stopdist[index][i];
                rates[i]=index;
            }
        }
    }
    if(mindist[n]!=INT_MAX)cout<<mindist[n]<<endl;
    else cout<<-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<rates[i]<<" -> "<<i<<endl;
    }
    return 0;
}