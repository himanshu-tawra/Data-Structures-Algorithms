// postOrder
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

void postOrder(Node* root){
	if(!root){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}


int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	postOrder(root);

	return 0;
}
