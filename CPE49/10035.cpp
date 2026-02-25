#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=-1,b=-1;
    while(true){
        cin>>a>>b;
        if(a==0&&b==0) return 0;
        int result[11], carry=0;
        for(int i=0;i<11;i++)result[i]=0;
        for(int i=0;i<11;i++){
            result[i]=a%10+b%10;
            b/=10;
            a/=10;
        }
        for(int i=0;i<10;i++){
            if(result[i]>9){
                carry++;
                result[i+1]+=result[i]/10;
            }
        }
        if(carry==0) cout<<"No carry operation.\n";
        else if(carry==1) cout<<"1 carry operation.\n";
        else cout<<carry<<" carry operations.\n";
    }
}