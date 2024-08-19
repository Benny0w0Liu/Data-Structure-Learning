#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* left, *right;
	Node(){
		left=right=NULL;
	}
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
Node* insert(Node* root, int x){
	if(root==NULL){//if empty
		root=new Node(x);
	}else if(x<=root->data){//if x <= root, insert to left
		root->left = insert(root->left, x);
	}else{//if x > root, insert to right
		root->right = insert(root->right, x);
	}
	return root;
}
bool search(Node* root, int x){
	if(root==NULL){
		return false;
	}else if(root->data==x){
		return true;
	}else if(x<=root->data){
		search(root->left, x);
	}else{
		search(root->right, x);
	}
}
int minimum(Node* root){
	if(root==NULL){
		cout<<"the tree is empty";
		return 404;
	}
	if(root->left->left==NULL)return root->left->data;
	return minimum(root->left);
}
int maximum(Node* root){
	if(root==NULL){
		cout<<"the tree is empty";
		return 404;
	}
	if(root->right->right==NULL)return root->right->data;
	return maximum(root->right);
}
int height(Node* root){
	if(root==NULL) return -1;
	int leftHeight=height(root->left), right_Height=height(root->right);
	if(leftHeight>right_Height){
		return leftHeight+1;
	}else{
		return right_Height+1;
	}
}
void print(Node* root, string prefix){
	if(root!=NULL){
		print(root->left,prefix+ "   ");
		cout<< prefix << root->data << endl;
		print(root->right,prefix+ "   ");
	}
}
int main(){
	Node* root=NULL;
	root = insert(root,10);
	root = insert(root,15);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	root = insert(root,2);
	print(root,"");
	cout<<"height of tree : "<<height(root)<<endl;
	cout<<"minimum : "<<minimum(root)<<endl;
	cout<<"maximum : "<<maximum(root)<<endl;
	int n=25;
	if(search(root, n))cout<<n<<" founded."<<endl;
	else cout<<n<<" is not in the tree"<<endl;
}
