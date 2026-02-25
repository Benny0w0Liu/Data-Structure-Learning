#include <iostream>
using namespace std;
int main(){
    int Case;
    cin>>Case;
    for(int C=0;C<Case;C++){
        int a,b;
        cin>>a>>b;
        if(a-b>=0&&(a+b)%2==0) cout<<(a+b)/2<<" "<<(a-b)/2<<"\n";
        else cout<<"impossible\n";
    }
}