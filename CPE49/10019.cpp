#include<bits/stdc++.h>
using namespace std;
int Dec2Bin(int Dec){
    int count=0;
    while(Dec>0){
        if(Dec%2==1) count++;
        Dec/=2;
    }
    return count;
}
int Str2Dec(string Str, int base){
    int ans=int(Str[0]-'0');
    for(int i=1;i<Str.length();i++){
        ans*=base;
        ans+=int(Str[i]-'0');
    }
    return ans;
}
int main(){
    int line;
    cin>>line;
    for(int curline=0;curline<line;curline++){
        string N;
        cin>>N;
        cout<<Dec2Bin(Str2Dec(N,10))<<" "<<Dec2Bin(Str2Dec(N,16))<<endl;
    }
}