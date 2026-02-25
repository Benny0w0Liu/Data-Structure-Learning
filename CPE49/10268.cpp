#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main(){
    long long int val;
    vector<long long int> poly;
    while(cin>>val){
        long long int temp,ans=0,mul=1;
        string input;
        getline(cin,input);
        getline(cin,input);
        stringstream s(input);
        poly.clear();
        while(s>>temp) poly.push_back(temp);
        reverse(poly.begin(),poly.end());
        for(int i=1;i<poly.size();i++){
            ans+=poly[i]*i*mul;
            mul*=val;
        }
        cout<<ans<<endl;
    }
}