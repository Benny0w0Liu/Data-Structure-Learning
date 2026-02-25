#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    while(cin>>n){
        ans=n;
        while(n>=3){
            ans+=n/3;
            n=n/3+n%3;
        }
        ans+=int(n==2);
        cout<<ans<<endl;
    }
}