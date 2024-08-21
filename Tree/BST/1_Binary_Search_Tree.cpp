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
void insert(Node** rootPtr, int x){
	Node* root = *rootPtr;
	if(*rootPtr==NULL){//if empty
		*rootPtr=new Node(x);
	}else if(x<=root->data){//if x <= root, insert to left
		insert(&(root->left), x);
	}else{//if x > root, insert to right
		insert(&(root->right), x);
	}
}
Node* search(Node* root, int x){
	if(root==NULL){
		return NULL;
	}else if(root->data==x){
		return root;
	}else if(x<=root->data){
		search(root->left, x);
	}else{
		search(root->right, x);
	}
}
Node* minimum(Node* root){
	if(root==NULL){
		cout<<"the tree is empty";
		return NULL;
	}
	if(root->left==NULL)return root;
	return minimum(root->left);
}
Node* maximum(Node* root){
	if(root==NULL){
		cout<<"the tree is empty";
		return NULL;
	}
	if(root->right==NULL)return root;
	return maximum(root->right);
}
void print(Node* root, string prefix){
	if(root!=NULL){
		print(root->left,prefix+ "   ");
		cout<< prefix << root->data << endl;
		print(root->right,prefix+ "   ");
	}
}
bool isBST(Node* root){
	if(root==NULL || (root->left==NULL && root->right==NULL)) {
		return true;
	}else if(root->left!=NULL && root->right!=NULL){
		return root->left->data <= root->data && root->right->data > root->data && isBST(root->left) && isBST(root->right);
	}else if(root->left==NULL){
		return root->right->data > root->data && isBST(root->right);
	}else if(root->right==NULL){
		return root->left->data <= root->data && isBST(root->left);
	}
}
void deleteNode(Node** rootPtr, int x){
	Node* root= *rootPtr;
	if(*rootPtr==NULL)return;
	if(x<root->data){
		deleteNode(&(root->left), x);//visit left
	}else if(x>root->data){
		deleteNode(&(root->right), x);//visit right
	}else{
		if(root->right==NULL && root->left==NULL){//0 child
			delete *rootPtr;
			*rootPtr=NULL;
		}else if(root->left==NULL){//1 child
			Node* temp = *rootPtr;
			*rootPtr = (*rootPtr)->right;
			delete temp;
		}else if(root->right==NULL){//1 child
			Node* temp = *rootPtr;
			*rootPtr = (*rootPtr)->left;
			delete temp;
		}else{//2 children	
			Node*  min = minimum((*rootPtr)->right);
			(*rootPtr)->data = min->data;
			deleteNode(&(root->right),min->data);
		}
	}
}
Node* getInorderSuccessor(Node* root, int data){
	Node* current = search(root, data);
	if(current==NULL) return NULL;
	if(current->right!=NULL){
		return minimum(root->right);
	}else{
		Node* successor = NULL;
		Node* ancestor = root;
		while(current!=ancestor){
			if(current->data<ancestor->data){
				successor=ancestor;
				ancestor=ancestor->left;
			}else{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}
}
int main(){
	Node* root=NULL;
	insert(&root,10);
	insert(&root,15);
	insert(&root,20);
	insert(&root,25);
	insert(&root,8);
	insert(&root,12);
	insert(&root,2);
	deleteNode(&root,15);
	
	print(root,"");
	
	cout<<"minimum : "<<minimum(root)->data<<endl;
	cout<<"maximum : "<<maximum(root)->data<<endl;
	
	int n=15, m=12;
	if(search(root, n))cout<<search(root, n)->data<<" founded, at "<<search(root, n)<<endl;
	else cout<<n<<" is not in the tree"<<endl;
	
	cout<<"inorder successor of "<<m<<" is "<<getInorderSuccessor(root,m)->data<<endl;
	
	Node* root1=new Node(0);
	root1->left=new Node(1);
	root1->right=new Node(2);
	root1->left->left=new Node(3);
	root1->left->right=new Node(4);
	root1->left->right->right=new Node(5);
	Node* root2=new Node(4);
	root2->left=new Node(1);
	root2->right=new Node(5);
	root2->left->left=new Node(0);
	root2->left->right=new Node(2);
	root2->left->right->right=new Node(3);
	if(isBST(root1))cout<<"root1 is BST"<<endl;
	else cout<<"root1 is not BST"<<endl;
	if(isBST(root2))cout<<"root2 is BST"<<endl;
	else cout<<"root2 is not BST"<<endl;
}
