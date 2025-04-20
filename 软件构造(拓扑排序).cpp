#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
int main(){
    cin>>n>>m;
    vector<ll> inagree(n,0);
    unordered_map<ll,vector<ll>> rels;
    vector<ll> result;
    while(m--){
        ll s,e;
        cin>>s>>e;
        rels[s].push_back(e);
        inagree[e]++;
    }
    queue<ll> q;
    for(int i=0;i<n;i++){
        if(inagree[i]==0) q.push(i);
    }
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        result.push_back(cur);
        for(ll i=0;i<rels[cur].size();i++){
            inagree[rels[cur][i]]--;
            if(inagree[rels[cur][i]]==0) q.push(rels[cur][i]);
        }
    }
    if(result.size()==n){
        for(ll i=0;i<result.size()-1;i++){
            cout<<result[i]<<" ";
        }
        cout<<result[result.size()-1];
    }
    else {
        cout<<-1;
    }
    return 0;
}