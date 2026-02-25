#include<iostream>
#include<string>
using namespace std;
string N="cdefgabCDEFGAB";
bool F[14][10]={
{0,1,1,1,0,0,1,1,1,1},//c
{0,1,1,1,0,0,1,1,1,0},//d
{0,1,1,1,0,0,1,1,0,0},//e
{0,1,1,1,0,0,1,0,0,0},//f
{0,1,1,1,0,0,0,0,0,0},//g
{0,1,1,0,0,0,0,0,0,0},//a
{0,1,0,0,0,0,0,0,0,0},//b
{0,0,1,0,0,0,0,0,0,0},//C
{1,1,1,1,0,0,1,1,1,0},//D
{1,1,1,1,0,0,1,1,0,0},//E
{1,1,1,1,0,0,1,0,0,0},//F
{1,1,1,1,0,0,0,0,0,0},//G
{1,1,1,0,0,0,0,0,0,0},//A
{1,1,0,0,0,0,0,0,0,0}//B
};
int main(){
    int Cnum;
    cin>>Cnum;
    string song;
    getline(cin,song);
    for(int C=0;C<Cnum;C++){
        getline(cin,song);
        int ans[10]={0,0,0,0,0,0,0,0,0,0};
        bool press[10]={0,0,0,0,0,0,0,0,0,0};
        for(int i=0;i<song.length();i++){
            int pos=0;
            for(int j=1;j<15;j++){
                if(song[i]==N[j]){
                    pos=j;
                    break;
                }
            }
            for(int j=0;j<10;j++){
                if(press[j]==0&&F[pos][j]==1){
                    press[j]=1;
                    ans[j]++;
                }else if(press[j]==1&&F[pos][j]==0) press[j]=0;
            }
        }
        for(int i=0;i<9;i++) cout<<ans[i]<<" ";
        cout<<ans[9]<<endl;
    }
}