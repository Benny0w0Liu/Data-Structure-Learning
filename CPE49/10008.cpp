#include<bits/stdc++.h>
using namespace std;
int main(){
    int inNum,Char[27],max=-1;
    for(int i=0;i<27;i++) Char[i]=0;
    cin>>inNum;
    string input[inNum];
    getchar();
    for(int i=0;i<inNum;i++) getline(cin,input[i]);
    for(int i=0;i<inNum;i++){
        for(int j=0;j<input[i].length();j++){
            if(input[i][j]>='a'&&input[i][j]<='z') Char[int(input[i][j])-int('a')]++;
            else if(input[i][j]>='A'&&input[i][j]<='Z') Char[int(input[i][j])-int('A')]++;
        }
    }
    while(max!=26){
        max=26;
        for(int i=0;i<26;i++) if(Char[i]>Char[max]) max=i;
        if(max==26) break;
        cout<<char('A'+max)<<" "<<Char[max]<<endl;
        Char[max]=0;
    }
    
    return 0;
}