#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y,d,cnt=0;
    cin>>y>>d;
    for(int year=y;year<=y;year++){
        for(int month=1;month<=12;month++){
            for(int day=1;day<=31;day++){
                if(month==1||month==3||month==5||month==7||month==8||month==10||month==12);
                else if(month==2){
                    if(((year%4==0) && (year%100!=0))||(year%400==0)) {
                        if(day>29) break;
                    }
                    else {
                        if(day>28) break;
                    }
                }
                else {
                    if(day>30) break;
                }
                cnt++;
                if(cnt==d) cout<<month<<endl<<day<<endl;
            }
        }
    }
    return 0;
}
