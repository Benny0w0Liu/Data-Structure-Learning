#include <bits/stdc++.h>
using namespace std;
int main(){
    int Case;
    string terms;
    cin>>Case;
    cin.ignore();
    map<string,int> tree;
    getline(cin,terms);
    for(int c=0;c<Case;c++){
        int total=0;
        tree.clear();
        while(getline(cin,terms)){
            if(terms.length()==0) break;
            if(tree.count(terms)==0)tree[terms]=1;
            else tree[terms]=tree[terms]+1;
            total++;
        }
        for(auto itr=tree.begin();itr!=tree.end();itr++){
            cout<<itr->first;
            printf(" %.4f\n",double(double(itr->second)*100/double(total)));
        }
        if(c!=Case-1) cout<<"\n";
    }
}