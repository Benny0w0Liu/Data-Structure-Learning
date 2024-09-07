#include<iostream> 
#include<vector>
using namespace std;
class Edge{
public:
	int start;
	int end;
	Edge(int a, int b){
		start=a;
		end=b;
	}
};

class Graph{
public:
	vector<char> vertexList;
	vector<Edge> EdgeList;
};

int main(){
	
}
