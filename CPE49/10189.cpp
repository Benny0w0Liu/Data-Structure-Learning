#include <bits/stdc++.h>
using namespace std;
int dir[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int main(){
    char map[105][105],newM[105][105];
    int w,h,Count=1;
    cin>>w>>h;
    while(w!=0&&h!=0){
        string s;
        for(int i=0;i<w;i++){
            cin>>s;
            for(int j=0;j<h;j++) map[i][j]=s[j];
        }
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(map[i][j]=='*'){
                    newM[i][j]='*';
                    continue;
                }
                int bomb=0;
                for(int k=0;k<8;k++){
                    if(i+dir[k][0]<0||i+dir[k][0]>=w||j+dir[k][1]<0||j+dir[k][1]>=h) continue;
                    if(map[i+dir[k][0]][j+dir[k][1]]=='*') bomb++;
                }
                newM[i][j]='0'+bomb;
            }
        }
        if(Count>1)cout<<endl;
        cout<<"Field #"<<Count<<":"<<endl;
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++) cout<<newM[i][j];
            cout<<endl;
        }
        Count++;
        cin>>w>>h;
    }
}