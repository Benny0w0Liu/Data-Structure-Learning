#include<iostream>
#include<stack>
#include <cstring>
using namespace std;
void Reverse(char C[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		S.push(C[i]);
	}
	for(int i=0;i<n;i++){
		C[i]=S.top();
		S.pop();
	}
}
int main(){
	char C[101];
	gets(C);
	Reverse(C,strlen(C));
	cout<<C;
} 
