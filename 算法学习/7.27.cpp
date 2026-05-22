#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
     int x,y,z;
     int ml=INT_MAX,mr=INT_MIN;
     while(cin>>x>>y>>z){
          ml=min(ml,x);
          mr=max(mr,z);
          for(int i=x;i<z;i++){
               if(a[i]<y) a[i]=y;
          }
     }
     for(int i=ml;i<=mr;i++){
          if(a[i]!=a[i-1]){
               if(a[i]==0){
                    cout<<i<<" "<<0;
               }
               else{
                    cout<<i<<" "<<a[i];
               }
          }
     }
     return 0;
}