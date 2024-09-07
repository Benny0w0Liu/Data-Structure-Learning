#include<iostream> 
using namespace std;
class Edge{
public:
	char endVertex;
	int weight;
};
class Vertex{
public:
	vector<Edge> AdjacencyList;
};
class Graph{
public:
	vector<Vertex> vertexList;
};
int main(){
	
}
