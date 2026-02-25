#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    long long int I;
    cin>>I;
    while(I!=0){
        string bin="";
        while(I>0){
            bin=char('0'+I%2)+bin;
            I/=2;
        }
        printf("The parity of %s is %d (mod 2).\n",bin.c_str(),count(bin.begin(),bin.end(),'1'));
        cin>>I;
    } 
}