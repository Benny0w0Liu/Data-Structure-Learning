#include <iostream>
#include <string>
using namespace std;
int Directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//NESW
string DirName="NESW";
int main(){
    int height, width, x, y;
    char dir;
    string path;
    cin>>width>>height;
    int scent[51][51];
    for(int i=0;i<51*51;i++)scent[i/51][i%51]=false;
    while(cin>>x>>y>>dir>>path){
        int curCord[2]={x,y}, curDir=3;
        bool fall=false;
        if(dir=='N') curDir=0;
        else if(dir=='E')curDir=1;
        else if(dir=='S')curDir=2;
        for(int i=0;i<path.length();i++){
            if(path[i]=='L'){ 
                curDir--;
                if(curDir<0) curDir=3;
            }else if(path[i]=='R'){ 
                curDir++;
                if(curDir>3) curDir=0;
            }else {
                curCord[0]+=Directions[curDir][0];
                curCord[1]+=Directions[curDir][1];
                if(curCord[0]<0||curCord[1]<0||curCord[0]>width||curCord[1]>height){
                    curCord[0]-=Directions[curDir][0];
                    curCord[1]-=Directions[curDir][1];
                    if(scent[curCord[0]][curCord[1]]) continue;
                    scent[curCord[0]][curCord[1]]=true;
                    fall=true;
                    break;
                }
            }
        }
        cout<<curCord[0]<<" "<<curCord[1]<<" "<<DirName[curDir];
        if(fall) cout<<" LOST\n";
        else cout<<"\n";
    }
}