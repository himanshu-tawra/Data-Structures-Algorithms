// postOrderIterative.cpp
//inorderIterative
//InorderRecursive
//Preorder Traversal
#include<iostream>
#include<stack>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = right = NULL;
	}
};

void postOrderIterative(Node* root){
	if(!root){
		return;
	}
	stack<Node*> S;
	Node* prev = NULL;
	do{
		while(root){
			S.push(root);
			root = root->left;
		}
		while(root == NULL && !S.empty()){
			root = S.top();
			if(root->right == NULL || root->right == prev){
				cout<<root->data<<" ";
				S.pop();
				prev = root;
				root = NULL;
			}
			else{
				root = root->right;
			}
		}
	}while(!S.empty());
}

int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	postOrderIterative(root);

	return 0;
}