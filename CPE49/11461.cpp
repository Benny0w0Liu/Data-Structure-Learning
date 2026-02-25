#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    while(a!=0||b!=0){
        int ans=0;
        for(int i=1;i*i<=b;i++){
            if(i*i>=a)ans++;
        }
        cout<<ans<<endl;
        cin>>a>>b;
    }
}