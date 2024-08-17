#include<iostream>
#include<stack>
#include <cstring>
using namespace std;
void InfixToPostfix(char str[]){
    char result[101]={'\0'};
    stack<char*> S;//storage operators and parentheses
    const char* d = " ";
    char *p;
    p = strtok(str, d);
    while (p != NULL) {
    	if(strcmp(p,"(")==0){
            S.push(p);//push the parentheses
        //if p==')', then close the parentheses
        }else if(strcmp(p,")")==0){
            //push all the operator in the parentheses, until the left parentheses and pop it out
            while(strcmp(S.top(),"(")!=0){
                strcat(result, S.top());
                strcat(result, " ");
                S.pop();
            }
            S.pop();
        }
        //if p == operators
        else if(strcmp(p,"+")==0||strcmp(p,"-")==0||strcmp(p,"*")==0||strcmp(p,"/")==0){
            //if p =="+" or "-" then check if there are "*" and "/" in stack
            if((strcmp(p,"+")==0||strcmp(p,"-")==0) && !S.empty()){
                //if S.top() == "*" or "/" then add them first (including the operators storage before)
                if(strcmp(S.top(),"*")==0||strcmp(S.top(),"/")==0){
                    while(strcmp(S.top(),"(")!=0){//until the parentheses
                        strcat(result, S.top());
                        S.pop();
                        strcat(result, " ");
                    }
                }
            }
            S.push(p);//push into stack
    	}else{
    	    strcat(result, p);//add operands directerlly into stack
    	}
    	if(result[strlen(result)-1]!=' '&&strlen(result)!=0) strcat(result, " ");
        p = strtok(NULL, d);		   
    }
    while(!S.empty()){//add rest of the operators
    	strcat(result, S.top());
    	S.pop();
    	strcat(result, " ");
    }
    strncpy(str, result, 101);
}
int main(){
    char str[101];
    cout<<"Input your formula, please add space between operators and operands"<<endl;
    cin.getline(str,101);
    InfixToPostfix(str);
    cout<<str;
} 
