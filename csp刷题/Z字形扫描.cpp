#include<bits/stdc++.h>
using namespace std;
int nums[505][505];
int main(){
    int n;
    cin>>n;
    vector<int> result;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>nums[i][j];
        }
    }
    int isright=1;
    bool isline=true;
    bool flag=false;
    int x=1,y=1;
    result.push_back(nums[1][1]);
    if(n!=1)
    while(!flag){
/*
        for(int i=0;i<result.size()-1;i++){
            cout<<result[i]<<" ";
        }
        cout<<result[result.size()-1]<<endl;
*/
        if(isright==1){
            y++;
            result.push_back(nums[x][y]);
            if(x==n&&y==n) flag=true;
            isright=0;
            int nx=x+1;
            int ny=y-1;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
            isline=false;
            else isline=true;
        }
        else if(isright==-1){
            x++;
            result.push_back(nums[x][y]);
            if(x==n&&y==n) flag=true;
            isright=0;
            int nx=x+1;
            int ny=y-1;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
            isline=false;
            else isline=true;
        }
        else{
            if(isline==false){
               int nx=x+1;
               int ny=y-1;
               if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                 x+=1;
                 y-=1;
                 result.push_back(nums[x][y]);
                 if(x==n&&y==n) flag=true;
               }
               else{
                if(nx>=1&&nx<=n) isright=-1;
                else isright=1;
                //cout<<isright<<endl;
               } 
            }
            else{
               int nx=x-1;
               int ny=y+1;
               if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                 x-=1;
                 y+=1;
                 result.push_back(nums[x][y]);
                 if(x==n&&y==n) flag=true;
               }
               else{
                if(ny>=1&&ny<=n) isright=1;
                else isright=-1;
               } 
            }
        }
    }
    for(int i=0;i<result.size()-1;i++){
        cout<<result[i]<<" ";
    }
    cout<<result[result.size()-1];
    return 0;
}