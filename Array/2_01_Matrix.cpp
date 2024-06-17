#include <iostream>
using namespace std; 
class Matrix{
public:
	int row,col;
	int** matrix;
	Matrix(){};
	Matrix(int r,int c){
		row=r; col=c;
  		matrix = new int*[r];
  		for(int i=0;i<r;i++){
    		matrix[i]=new int[c];
  		}
	}
	Matrix transpose(){
		Matrix result(col,row);
		for(int i=0;i<col;i++){
			for(int j=0;j<row;j++){
				result.matrix[i][j]=matrix[j][i];
			}
		}
		return result;
	}
	void output(){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	~Matrix(){
		for(int i=0;i<row;i++){
			delete [] matrix[i];
		}
		delete [] matrix;
	}
	
};
int main(){
	Matrix test(3,4);
	cout<<"Input your "<<test.row<<"*"<<test.col<<" elements\n";
	for(int i=0;i<test.row;i++){
		for(int j=0;j<test.col;j++){
			cin>>test.matrix[i][j];
		}
	}
	cout<<"Before transpose:"<<endl;
	test.output();
	
	Matrix trans = test.transpose();
	trans.transpose();
	cout<<"After transpose:"<<endl;
	trans.output();
} 
