#include <iostream>
using namespace std;
class Polynomial{
public:
    int *coefficient;
    int size;
    Polynomial(int n){
        size = n;
        coefficient = new int[n];
    }
    void Set_Polynomial(){
        for (int i = 0; i < size; i++){
            cout << "coefficient of x^" << i << " = ";
            cin >> coefficient[i];
        }
    }
    void Print_Polynomial(){
        for (int i = size - 1; i > -1; i--){
            cout << coefficient[i] << "x^" << i;
            if (i != 0){
                cout << " + ";
            }
            else{
                cout << endl;
            }
        }
    }
    ~Polynomial(){
        delete [] coefficient;
    }
};
int main(){
    Polynomial test(4);
    test.Set_Polynomial();
    test.Print_Polynomial();
    return 0;
}
