#include <iostream>
using namespace std; 
class Matrix{
public:
	int row,col,none_zero;
	int** value;
	Matrix(){};
	Matrix(int r,int c,int n){
		row=r; col=c; none_zero = n;
  		value = new int*[n];
  		for(int i=0;i<n;i++){
    		value[i]=new int[3];//{row, col, value}
  		}
	}
	Matrix transpose(){
		Matrix result(col,row,none_zero);
		for(int i=0;i<none_zero;i++){
			int r = value[i][0], c = value[i][1];
			result.value[i][0] = c;
			result.value[i][1] = r;
			result.value[i][2] = value[i][2];
		}
		return result;
	}
	const Matrix operator * (const Matrix& A){
		if(A.row != col){
			cout<<"Two matrix doesn't match!"<<endl;
			exit(1);
		}
		int n=0;//count none_zero value in new matrix
		int pos[none_zero][3];// temp
		for(int i=0;i<none_zero;i++){
			pos[i][0]=-1;pos[i][1]=-1;pos[i][2]=0;
		}
		for(int i=0;i<none_zero;i++){
			for(int j=0;j<A.none_zero;j++){
				if(value[i][1] == A.value[j][0]){
					bool if_exist = 0;
					for(int k=0;k<n;k++){
						if( pos[k][0]==value[i][0] && pos[k][1]==A.value[j][1]){
							pos[k][2]+=value[i][2]*A.value[j][2];
							if_exist = 1;
							break;
						}
					}
					if(!if_exist){
						pos[i][0]=value[i][0];
						pos[i][1]=A.value[j][1];
						pos[i][2]=value[i][2]*A.value[j][2];
						n++;
					}
				}
			}
		}
		Matrix result(row,A.col,n);
		for(int i=0;i<n;i++){
			result.value[i][0] = pos[i][0];
			result.value[i][1] = pos[i][1];
			result.value[i][2] = pos[i][2];
		}
		return result;
	}
	void output(){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				bool if_exist = 0;
				for(int k=0;k<none_zero;k++){
					if(value[k][0] == i && value[k][1] == j ){
						if_exist = 1;
						cout<<value[k][2]<<" "; 
						break;
					}
				}
				if(!if_exist){
					cout<<"0 ";
				}
			}
			cout<<endl;
		}
	}
	~Matrix(){
		for(int i=0;i<none_zero;i++){
			delete [] value[i];
		}
		delete [] value;
	}
	
};
int main(){
	Matrix test(3,4,3);
	cout<<"Input your "<<test.none_zero<<" elements (row col value)\n";
	cout<<0<<" <= row <= "<<test.row-1<<endl;
	cout<<0<<" <= col <= "<<test.col-1<<endl;
	for(int i=0;i<test.none_zero;i++){
		cout<<i+1<<". ";
		cin>>test.value[i][0]>>test.value[i][1]>>test.value[i][2];
	}
	cout<<"Before transpose:"<<endl;
	test.output();
	
	Matrix trans = test.transpose();
	trans.transpose();
	cout<<"After transpose:"<<endl;
	trans.output();
	
	cout<<"Transpose matrix * Original matrix:"<<endl;
	Matrix time = trans*test;
	time.output();
} 
