#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};
struct edge{
    int to,val;
    edge(int newto,int newval):to(newto),val(newval){}
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>rates(n+1);
    vector<list<edge>> edges(n+1);
    vector<bool>vits(n+1,false);
    vector<int>mindist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    int start=1;
    int end=n;
    mindist[1]=0;
    pq.push({start,0});
    while(!pq.empty()){
        pair<int,int> cur=pq.top(); pq.pop();
        vits[cur.first]=true;
        for(edge e:edges[cur.first]){
            if(!vits[e.to]&&mindist[cur.first]+e.val<mindist[e.to]){
                mindist[e.to]=mindist[cur.first]+e.val;
                pq.push({e.to,mindist[e.to]});
                rates[e.to]=cur.first;
            }
        }
    }
    if(mindist[n]!=INT_MAX) cout<<mindist[n]<<endl;
    else cout<<-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<rates[i]<<" "<<i<<endl;
    }
    return 0;
}
