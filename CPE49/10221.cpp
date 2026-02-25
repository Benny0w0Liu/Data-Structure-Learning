#include <bits/stdc++.h>
using namespace std;
const double ER=6440.0;
int main(){
    double s,a;
    string unit;
    while(cin>>s>>a>>unit){
        double arc=0,chord=0,r=ER+s;
        if(unit[0]=='m') a/=60.0;
        if(a>180)a=360.0-a;
        printf("%.6f %.6f\n",2.0*r*M_PI*a/360.0,sqrt(2.0*r*r-2.0*r*r*cos(a*M_PI/180.0)));
    }
}