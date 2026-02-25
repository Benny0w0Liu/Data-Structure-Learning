#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int M,N,Q;
        cin>>M>>N>>Q;
        cout<<M<<" "<<N<<" "<<Q<<endl;
        char Map[M][N];
        string temp;
        getline(cin,temp);
        for(int i=0;i<M;i++){
            getline(cin,temp);
            for(int j=0;j<N;j++) Map[i][j]=temp[j];
        }
        for(int q=0;q<Q;q++){
            int r,c,side=1;
            cin>>r>>c;
            char Char=Map[r][c];
            bool in=true;
            while(r>=0&&c>=0){
                r--;c--;
                for(int i=0;i<side+2;i++){
                    if(r+i<0||r+i>=M||c<0||c>=N||Map[r+i][c]!=Char) in=false;
                }
                if(!in) break;
                for(int i=0;i<side+2;i++){
                    if(r<0||r>=M||c+i<0||c+i>=N||Map[r][c+i]!=Char) in=false;
                }
                if(!in) break;
                for(int i=0;i<side+2;i++){
                    if(r+i<0||r+i>=M||c+side+1<0||c+side+1>=N||Map[r+i][c+side+1]!=Char) in=false;
                }
                if(!in) break;
                for(int i=0;i<side+2;i++){
                    if(r+side+1<0||r+side+1>=M||c+i<0||c+i>=N||Map[r+side+1][c+i]!=Char) in=false;
                }
                if(!in) break;
                side+=2;
            }
            cout<<side<<"\n";
        }
    }
}