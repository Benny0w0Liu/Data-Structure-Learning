#include <iostream>
using namespace std;
int main(){
    int Case;
    cin>>Case;
    for(int c=1;c<=Case;c++){
        int a,b,ans=0;
        cin>>a>>b;
        if(a%2==0)a++;
        for(int i=a;i<=b;i+=2) ans+=i;
        cout<<"Case "<<c<<": "<<ans<<endl;
    }
}