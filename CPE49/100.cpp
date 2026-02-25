#include <iostream>
using namespace std;
int main(){
    int A,B;
    while(cin>>A>>B){
        int max_length=0;
        for(int i=min(A,B);i<=max(A,B);i++){
            int cur=i,cur_length=0;
            while(cur!=1){
                if(cur%2==0) cur/=2;
                else cur=cur*3+1;
                cur_length++;
            }
            if(cur_length>max_length)max_length=cur_length;
        }
        cout<<A<<" "<<B<<" "<<max_length+1<<endl;
    }
}