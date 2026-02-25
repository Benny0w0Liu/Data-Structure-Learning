#include<bits/stdc++.h>
using namespace std;
int main(){
    int numIn,fib[40]={1,2};
    for(int i=2;i<=40;i++) fib[i]=fib[i-1]+fib[i-2]; 
    cin>>numIn;
    for(int term=0;term<numIn;term++){
        int dec, storeDEC, currentDigit=39;
        string fibBase="";
        cin>>dec;
        storeDEC=dec;
        while(dec>0){
            if(dec>=fib[currentDigit]){
                dec-=fib[currentDigit];
                fibBase+="1";
            }else if(fibBase.length()>0) fibBase+="0";
            currentDigit--;
        }
        for(int i=currentDigit;i>=0;i--) fibBase+="0"; 
        cout<<storeDEC<<" = "<<fibBase<<" (fib)"<<endl;
    }
}