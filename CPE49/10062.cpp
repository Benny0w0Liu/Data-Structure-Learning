#include<bits/stdc++.h>
using namespace std;
class Char{
public:
    int N,C;
};
bool compare(Char a,Char b){
    if(a.C==b.C) return a.N>b.N;
    return a.C<b.C;
}
int main(){
    char str[1001];
    gets(str);
    while(true){
        Char Charecter[257];
        for(int i=0;i<=256;i++){
            Charecter[i].N=i;
            Charecter[i].C=0;
        }
        for(int i=0;i<strlen(str);i++) Charecter[int(str[i])].C++;
        sort(Charecter,Charecter+256,compare);
        for(int i=0;i<=256;i++){
            if(Charecter[i].C>0) cout<<Charecter[i].N<<" "<<Charecter[i].C<<endl;
        }
        if(gets(str))cout<<endl;
        else break;
    }
}