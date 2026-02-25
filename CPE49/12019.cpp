#include <iostream>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string week[7]= {"Friday","Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
int main(){
    int Case;
    cin>>Case;
    for(int c=0;c<Case;c++){
        int m,d,date=0;
        cin>>m>>d;
        for(int i=0;i<m-1;i++){
            date+=month[i];
        }
        date+=d;
        cout<<week[date%7]<<endl;
    }
}