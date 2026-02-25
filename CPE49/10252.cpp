#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string a,b;
    while(getline(cin, a)&& getline(cin, b)){
        string ans="";
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length();j++){
                if(a[i]==b[j]){
                    ans+=a[i];
                    b.erase(b.begin()+j);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}