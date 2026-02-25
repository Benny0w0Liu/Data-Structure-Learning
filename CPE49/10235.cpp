#include<bits/stdc++.h>
using namespace std;
long long int reverse(long long int n){
    int ans=0;
    while(n>0){
        ans*=10;
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main(){
    long long int n;
    bool Nprime[1000005]={true,true};
    for(int i=2;i<=1000000;i++) Nprime[i]=false;
    for(int i=2;i<=1000000;i++){
        if(!Nprime[i]){
            for(int j=i+i;j<=1000000;j+=i){
                Nprime[j]=true;
            }
        }
    }
    while(cin>>n){
        if(Nprime[n]){
            printf("%d is not prime.\n", n);
            continue;
        }
        long long int re=reverse(n);
        if(re != n && !Nprime[re]) printf( "%d is emirp.\n", n );
        else printf("%d is prime.\n", n);
    }
}