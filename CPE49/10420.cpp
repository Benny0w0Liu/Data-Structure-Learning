#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int main(){
    int n;
    string str;
    map <string, int> Count;
    cin>>n;
    getline(cin,str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        stringstream s(str);
        s>>str;
        if(Count.count(str)==0){
            Count[str]=1;
        }else{
            Count[str]=Count[str]+1;
        }
    }
    for(auto itr=Count.begin();itr!=Count.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}