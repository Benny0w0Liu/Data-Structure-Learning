#include <bits/stdc++.h>
using namespace std;
string key="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main(){
    char code[100000];
    gets(code);
    for(int i=0;i<strlen(code);i++){
        bool found=false;
        if(code[i]<='Z'&&code[i]>='A') code[i]='a'+code[i]-'A';
        if(code[i]==' ') continue;
        int pos=key.find(code[i]);
        code[i]=key[pos-2];
    }
    cout<<code<<endl;
}