#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,arr[3001];
    while(cin>>n){
        bool absNum[n],jolly=true;
        for(int i=0;i<n;i++) absNum[i]=false;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=1;i<n;i++) absNum[abs(arr[i]-arr[i-1])]=true;
        for(int i=1;i<n;i++){
            if(absNum[i]==false){
                jolly=false;
                break;
            }
        }
        if(jolly) cout<<"Jolly\n";
        else cout<<"Not jolly\n";
    }
}