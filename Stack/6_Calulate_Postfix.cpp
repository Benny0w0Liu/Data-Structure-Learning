#include<iostream>
#include<stack>
#include <cstring>
using namespace std;
int CalculatePostfix(char str[]){
    stack<int> S;//storage numbers
    const char* d = " ";
    char *p;
    p = strtok(str, d);
    while (p != NULL) {
    	if(strcmp(p,"+")==0||strcmp(p,"-")==0||strcmp(p,"*")==0||strcmp(p,"/")==0){
    		//take first two numbers and operate it if p is operator
    		int a=S.top();
    		S.pop();
    		int b=S.top();
    		//push back result
			if(strcmp(p,"+")==0) S.push(b+a);
			else if(strcmp(p,"-")==0) S.push(b-a);
			else if(strcmp(p,"*")==0) S.push(b*a);
			else if(strcmp(p,"/")==0) S.push(b/a);
		}else{
			S.push(atoi(p));//push p if it is a number
		}
        p = strtok(NULL, d);		   
    }
    return S.top();//it should be the only one in stack
}
int main(){
    char str[101];
    cout<<"Input your postfix formula, please add space between operators and operands"<<endl;
    cin.getline(str,101);
    int num=CalculatePostfix(str);
    cout<<num;
} 
