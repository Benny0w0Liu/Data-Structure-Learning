#include<iostream>
#include<string>
using namespace std;
int main(){
	//Input
	string text="",pattern="";
	cout<<"Input text: ";
	getline(cin,text);
	cout<<"Input pattern: ";
	cin>>pattern;
	//Deal with pattern
	int pattern_index[pattern.length()+1]={0,0};
	for(int i=2;i<pattern.length()+1;i++){
		if(pattern[i-1]==pattern[pattern_index[i-1]]){
			pattern_index[i]=pattern_index[i-1]+1;
		}else{
			pattern_index[i]=0;
		}
	}
	pattern =" "+pattern;//' ' can be any character except '\0'
	//Start compare
	int text_pos=0, pattern_pos=0;
	while(text_pos<text.length()){
		if(text[text_pos]==pattern[pattern_pos+1]){
			text_pos++;
			pattern_pos++;
			if(pattern_pos == pattern.length()-1){//find it
				cout<<"The first pattern start from "<<text_pos-pattern.length()+1<<endl<<text<<endl;
				for(int i=0;i<text_pos-pattern.length()+1;i++){
					cout<<" ";
				}
				for(int i=0;i<pattern.length()-1;i++){
					cout<<"^";
				}
				return 0;
			}
		}else{
			while(text[text_pos]!=pattern[pattern_pos+1]){
				pattern_pos = pattern_index[pattern_pos];
				if(pattern_pos==0){
					text_pos++;
					break;
				}
			}
		}
	}
	cout<<"Didn't find the pattern in the text"<<endl;
	return 0;
} 
