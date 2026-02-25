#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int arr[n],ans=0,mid1,mid2;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        mid1=arr[(n-1)/2];
        mid2=arr[n/2];
        for(int i=0;i<n;i++){
            if(arr[i]==mid1||arr[i]==mid2)ans++;
        }
        cout<<mid1<<" "<<ans<<" "<<mid2-mid1+1<<endl;
    }
}