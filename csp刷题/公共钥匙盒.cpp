#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    map<int,set<int>>start;
    map<int,set<int>>end;
    for(int i=1;i<=K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        start[b].insert(a);
        end[b+c].insert(a);
    }
    for(int i=0;i<=10200;i++){
        
    }
    return 0;
}
