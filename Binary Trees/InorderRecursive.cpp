//InorderRecursive
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

void inorderRecursive(Node* root){
	if(!root){
		return;
	}
	inorderRecursive(root->left);
	cout<<root->data<<" ";
	inorderRecursive(root->right);
}


int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	inorderRecursive(root);

	return 0;
}