#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int Case;
    cin>>Case;
    for(int c=1;c<=Case;c++){
        printf("Case %d:\n",c);
        int price[36],testC;
        for(int i=0;i<36;i++) cin>>price[i];
        cin>>testC;
        for(int t=0;t<testC;t++){
            int num, p[35];
            cin>>num;
            for(int i=2;i<37;i++){
                p[i-2]=0;
                int temp=num;
                while(temp>0){
                    p[i-2]+=price[temp%i];
                    temp/=i;
                }
            }
            int m=p[0];
            for(int i=1;i<35;i++) if(p[i]<m) m=p[i];
            cout<<"Cheapest base(s) for number "<<num<<":";
            for(int i=0;i<35;i++){
                if(p[i]==m) cout<<" "<<i+2;
            }
            cout<<endl;
        }
        if(c!=Case) cout<<endl;
    }
}