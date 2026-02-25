#include<iostream>
using namespace std;
int NewDir[4][6]={{4,0,2,3,5,1},{1,5,2,3,0,4},{3,1,0,5,4,2},{2,1,5,0,4,3}};//NSWE
int main(){
    int n;
    string in;
    while(cin>>n){
        if(n==0) break;
        int ini[6]={1,2,3,4,5,6},next[6];
        for(int i=0;i<n;i++){
            cin>>in;
            if(in[0]=='n'){
                for(int j=0;j<6;j++) next[j]=ini[NewDir[0][j]];
                for(int j=0;j<6;j++) ini[j]=next[j];
            }else if(in[0]=='s'){
                for(int j=0;j<6;j++) next[j]=ini[NewDir[1][j]];
                for(int j=0;j<6;j++) ini[j]=next[j];
            }else if(in[0]=='w'){
                for(int j=0;j<6;j++) next[j]=ini[NewDir[2][j]];
                for(int j=0;j<6;j++) ini[j]=next[j];
            }else{
                for(int j=0;j<6;j++) next[j]=ini[NewDir[3][j]];
                for(int j=0;j<6;j++) ini[j]=next[j];
            }
        }
        cout<<ini[0]<<endl;
    }
}