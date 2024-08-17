#include<iostream>
#include<stack>
#include <cstring>
using namespace std;
bool IfBalanced(char C[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		if(C[i]=='('||C[i]=='['||C[i]=='{'){
			S.push(C[i]);
		}else if(C[i]==')'||C[i]==']'||C[i]=='}'){
			if((C[i]==']' && S.top()=='[')||(C[i]==')' && S.top()=='(')||(C[i]=='}' && S.top()=='{'))S.pop();
			else return false;
		}
	}
	return true;
}
int main(){
	char C[101];
	gets(C);
	if(IfBalanced(C,strlen(C))) cout<<"It is Balanced"<<endl;
	else cout<<"It is opened"<<endl;
} 
