#include<bits/stdc++.h>
using namespace std;
long long int Bin2Dec(string bin){
    if(bin.length()<=1 || bin[0]=='0') return -1;
    long long int ans=0;
    for(int i=0;i<bin.length();i++){
        if(bin[i]=='1')ans+=pow(2,bin.length()-i-1);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int Case=1;Case<=n;Case++){
        string s1,s2;
        cin>>s1>>s2;
        long long int a=Bin2Dec(s1),b=Bin2Dec(s2);
        if(__gcd(a,b)<=1) cout<<"Pair #"<<Case<<": Love is not all you need!\n"; 
        else cout<<"Pair #"<<Case<<": All you need is love!\n";
    }
}