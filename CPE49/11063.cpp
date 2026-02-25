#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,Case=0;
    while(cin>>n){
        Case++;
        vector<int> arr,s;
        bool b2=true;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            if((i>=1&&arr[i-1]>=temp)||temp<1) b2=false; 
            arr.push_back(temp);
        }
        if(b2){
            for(int i=0;i<n-1;i++){
                for(int j=i;j<n;j++){
                    temp=arr[i]+arr[j];
                    if(count(s.begin(),s.end(),temp)==0){
                        s.push_back(temp);
                    }else{
                        b2=false;
                        break;
                    }
                }
                if(!b2) break;
            }
        }
        if(b2) cout<<"Case #"<<Case<<": It is a B2-Sequence.\n\n";
        else cout<<"Case #"<<Case<<": It is not a B2-Sequence.\n\n";
    }
}