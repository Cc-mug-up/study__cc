#include<bits/stdc++.h>
using namespace std;
vector<int> cnt(1005,0);
static bool cmp(int a,int b){
    if(cnt[a]==cnt[b]) return a<b;
    return cnt[a]>cnt[b];
}
int main(){
    int n;
    cin>>n;
    vector<int> rec;
    while(n--){
        int t;
        cin>>t;
        cnt[t]++;
        if(cnt[t]==1) rec.push_back(t);
        //��¼���洢 ��һ�γ��ֵ�����
    }
    sort(rec.begin(),rec.end(),cmp);
    for(auto& x:rec){
        cout<<x<<" "<<cnt[x]<<endl;
    }
    return 0;
}