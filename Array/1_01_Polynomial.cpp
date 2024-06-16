#include <iostream>
using namespace std;
int main(){
	int Polynomial[5] = {12, 7, 9, 13, 3};
	for (int i = 5 - 1; i > -1; i--){
		cout << Polynomial[i] << "x^" << i;
		if (i != 0){
			cout << " + ";
		}
	}
	return 0;
}
