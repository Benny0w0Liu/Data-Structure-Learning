#include <iostream>
using namespace std;
int g(int n){
    if(n<10) return n;
    int next=0;
    while(n>0){
        next+=n%10;
        n/=10;
    }
    return g(next);
}
int main(){
    int n;
    cin>>n;
    while(n!=0){
        cout<<g(n)<<endl;
        cin>>n;
    }
}