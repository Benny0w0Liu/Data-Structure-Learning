#include <bits/stdc++.h>
using namespace std;
int main(){
    int TestCase;
    cin>>TestCase;
    for(int Case=0;Case<TestCase;Case++){
        int N,P,count=0;
        cin>>N>>P;
        int H[P];
        for(int i=0;i<P;i++) cin>>H[i];
        for(int i=1;i<=N;i++){
            if(i%7==6 || i%7==0) continue;
            for(int j=0;j<P;j++){
                if(i%H[j]==0){
                    count++;
                    break;
                }
            }
        }
        cout<<count<<endl;
    }
}