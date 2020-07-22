//Preorder Traversal
#include<iostream>
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

void preOrderTaversal(Node* root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	preOrderTaversal(root->left);
	preOrderTaversal(root->right);
}



int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);


	preOrderTaversal(root);

	return 0;
}