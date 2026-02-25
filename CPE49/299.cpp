#include <bits/stdc++.h>
using namespace std;
int main(){
    int caseNum;
    cin>>caseNum;
    for(int c=0;c<caseNum;c++){
        int length, swapCount=0, temp=1;
        cin>>length;
        int train[length];
        for(int i=0;i<length;i++) cin>>train[i];
        while(temp>0){
            temp=0;
            for(int i=1;i<length;i++){
                if(train[i]<train[i-1]){
                    swap(train[i],train[i-1]);
                    temp++;
                }
            }
            swapCount+=temp;
        }
        cout<<"Optimal train swapping takes "<<swapCount<<" swaps.\n";
    }
}