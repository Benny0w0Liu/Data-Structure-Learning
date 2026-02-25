#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m;
    while(cin>>n>>m){
        bool b=false;
        vector<long long int> arr;
        if(m<=1 || n<m){
            b=true;
        }else{
            arr.push_back(n);
            while(n>1){
                if(n%m==0){
                    n/=m;
                    arr.push_back(n);
                }else{
                    b=true;
                    break;
                }
            }
        }
        if(b) cout<<"Boring!\n";
        else{
            for(int i=0;i<arr.size();i++){
                if(i==arr.size()-1)cout<<arr[i]<<"\n";
                else cout<<arr[i]<<" ";
            }
        }
    }
}