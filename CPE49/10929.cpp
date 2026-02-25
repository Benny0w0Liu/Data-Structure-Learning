#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    while(str.compare("0")!=0){
        int d=int(str[0]-'0');
        for(int i=1;i<str.length();i++){
            d=str[i]-'0'-d;
        }
        if(d%11==0) cout<<str<<" is a multiple of 11.\n";
        else cout<<str<<" is not a multiple of 11.\n";
        cin>>str;
    }
}