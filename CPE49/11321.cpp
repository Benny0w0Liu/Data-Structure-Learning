#include<iostream>
#include<algorithm>
using namespace std;
int M;
bool compare(int a, int b){
    if(a%M==b%M){
        if(a%2==0 && b%2!=0) return false;
        else if(a%2!=0 && b%2==0) return true;
        else if(a%2!=0 && b%2!=0) return a>b;
        else return a<b;
    }
    else return a%M < b%M;
}
int main(){
    int N;
    cin>>N>>M;
    while(N!=0||M!=0){
        int arr[N];
        cout<<N<<" "<<M<<"\n";
        for(int i=0;i<N;i++) cin>>arr[i];
        sort(arr,arr+N,compare);
        for(int i=0;i<N;i++) cout<<arr[i]<<"\n"; 
        cin>>N>>M;
    }
    cout<<"0 0\n";
}