#include<iostream>
#include<queue>
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
void preorder(Node* root){
	if(root!=NULL){
		cout<< root->data << " ";//D
		preorder(root->left);//L
		preorder(root->right);//R
	}
}
void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);//L
		cout<< root->data << " ";//D
		inorder(root->right);//R
	}
}
void postorder(Node* root){
	if(root!=NULL){
		postorder(root->left);//L
		postorder(root->right);//R
		cout<< root->data << " ";//D
	}
}
void levelOrder(Node* root){
	if(root!=NULL){
		queue<Node*> nodes;
		nodes.push(root);
		while(!nodes.empty()){
			if(nodes.front()!=NULL){
				cout<<nodes.front()->data<<" ";
				if(nodes.front()->left!=NULL){
					nodes.push(nodes.front()->left);
				}
				if(nodes.front()->right!=NULL){
					nodes.push(nodes.front()->right);
				}
				nodes.pop();
			}
		}
	}
}
void print(Node* root, string prefix){
	if(root!=NULL){
		print(root->left,prefix+ "   ");
		cout<< prefix << root->data << endl;
		print(root->right,prefix+ "   ");
	}
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
int main(){
	Node* root=new Node(0);
	root->left=new Node(1);
	root->right=new Node(2);
	root->left->left=new Node(3);
	root->left->right=new Node(4);
	root->left->right->right=new Node(5);
	print(root,"");
	cout<<endl<<endl<<"levelOrder(root);"<<endl;
	levelOrder(root);
	cout<<endl<<endl<<"preorder(root);"<<endl;
	preorder(root);
	cout<<endl<<endl<<"inorder(root);"<<endl;
	inorder(root);
	cout<<endl<<endl<<"postorder(root);"<<endl;
	postorder(root);
	cout<<endl<<endl<<"height : "<<height(root)<<endl;
}
