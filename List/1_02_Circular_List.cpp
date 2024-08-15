#include <iostream>
using namespace std;
template <class T>
T plus(T a, T b){
	return a+b;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<plus(a,b);
}
