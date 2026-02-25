#include<bits/stdc++.h>
using namespace std;
int main(){
    int S;
    cin>>S;
    for(int s=0;s<S;s++){
        float N,P,I;
        cin>>N>>P>>I;
        float ans=0, temp=pow(1-P,I-1);
        for(int i=0;i<100;i++){
            ans+=temp*P;
            temp*=pow(1-P,N);
        }
        printf("%.4f\n",ans);
    }
}