#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int S,D;
    while(cin>>S>>D){
        long long int num=S;
        while(num<D) num+=(++S);
        cout<<S<<endl;
    }
}