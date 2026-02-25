#include <bits/stdc++.h>
using namespace std;
int main(){
    int testCase;
    cin>>testCase;
    for(int Case=0;Case<testCase;Case++){
        int n;
        cin>>n;
        int streetNum[n];
        for(int i=0;i<n;i++) cin>>streetNum[i];
        sort(streetNum,streetNum+n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(i!=n/2) sum+=abs(streetNum[i]-streetNum[n/2]);
        }
        cout<<sum<<endl;
    }
}