#include <iostream>
#include <string>
using namespace std;
int str2num(string str){
    int Dsum=0;
    for(int i=0;i<str.length();i++) Dsum+=int(str[i]-'0');
    return Dsum; 
}
int degree(int n,int ans){
    if(n%9==0&&n!=9){
        int next=0;
        while(n>0){
            next+=n%10;
            n/=10;
        }
        return degree(next,ans+1);
    } 
    return ans;
}
int main(){
    string str;
    cin>>str;
    while(str.compare("0")!=0){
        if(str2num(str)%9==0)cout<<str<<" is a multiple of 9 and has 9-degree "<<degree(str2num(str),1)<<".\n";
        else cout<<str<<" is not a multiple of 9.\n";
        cin>>str;
    }
}