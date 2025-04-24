#include<bits/stdc++.h>
using namespace std;
int n,m;
int curs[2600][1500]={0};
typedef struct window{
    int x1,y1,x2,y2,index;
}window;
void update(window w){
    int x1=w.x1;
    int y1=w.y1;
    int x2=w.x2;
    int y2=w.y2;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            curs[i][j]=w.index;
        }
    }
}
int main(){
    cin>>n>>m;
    vector<window> wins(n+1);
    vector<int> result;
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        wins[i].index=i;
        wins[i].x1=a;
        wins[i].y1=b;
        wins[i].x2=c;
        wins[i].y2=d;
        update(wins[i]);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        if(curs[x][y]==0) result.push_back(0);
        else {result.push_back(curs[x][y]);update(wins[curs[x][y]]);} 
    }
    for(auto& x:result){
        if(x==0) cout<<"IGNORED"<<endl;
        else cout<<x<<endl;
    }
    return 0;
}