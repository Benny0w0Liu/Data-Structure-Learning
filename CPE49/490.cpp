#include <bits/stdc++.h>
using namespace std;
int main(){
    int indexI=0,indexJ=0,maxJ=0;
    char input[101][101];
    for(int i=0;i<101*101;i++)input[i/101][i%101]=0;
    while(gets(input[indexI])){
        if(strlen(input[indexI]) > maxJ) maxJ=strlen(input[indexI]); 
        indexI++;
    }
    for(int j=0;j<maxJ;j++){
        for(int i=indexI-1;i>=0;i--){
            if(j >= strlen(input[i])) cout<<" ";
            else cout<<input[i][j];
        }
        cout<<"\n";
    }
}