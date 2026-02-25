#include <iostream>
using namespace std;
int main(){
    int Case;
    cin>>Case;
    for(int C=1;C<=Case;C++){
        long long int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        cout<<"Case "<<C<<": "<<(ex+(ex+ey+1)*(ex+ey)/2)-(sx+(sx+sy+1)*(sx+sy)/2)<<endl;
    }
}