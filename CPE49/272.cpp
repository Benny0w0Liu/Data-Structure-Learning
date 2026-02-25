#include<bits/stdc++.h>
using namespace std;
int main(){
    string text,newText="";
    char temp=getchar();
    while(temp!=EOF){
        text+=temp;
        temp=getchar();
    }
    bool prev=false;
    for(int i=0;i<text.length();i++){
        if(text[i]=='"' && !prev){
            newText+="``";
            prev=true;
        }else if(text[i]=='"' && prev){
            newText+="''";
            prev=false;
        }else newText+=text[i];
    }
    cout<<newText;
}