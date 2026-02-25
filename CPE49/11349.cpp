#include <iostream>
using namespace std;
int main(){
    int Case;
    cin>>Case;
    for(int c=1;c<=Case;c++){
        char temp;
        int n;
        cin>>temp>>temp>>n;
        long long int matrix[n][n];   
        bool sym=true;
        for(int i=0;i<n*n;i++){
            cin>>matrix[i/n][i%n];
            if(matrix[i/n][i%n]<0) sym=false;
        }
        for(int i=0;i<n;i++){
            if(!sym) break;
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=matrix[n-i-1][n-j-1]){
                    sym=false;
                    break;
                }
            }
        }
        if(sym) printf("Test #%d: Symmetric.\n",c);
        else printf("Test #%d: Non-symmetric.\n",c);
    }
}