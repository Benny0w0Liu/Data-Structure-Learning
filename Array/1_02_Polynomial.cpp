#include <iostream>
using namespace std;

int main(){
    int Polynomial[2][2]= {{4,3},{0,12}};
    for (int i = 0; i < 2; i++){
    	if (i != 0){
            cout << " + ";
        }
        cout << Polynomial[i][1] << "x^" << Polynomial[i][0];
    }
    return 0;
}
