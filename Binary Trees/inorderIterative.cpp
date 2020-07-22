//inorderIterative

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

void inorderIterative(Node* root){
	if(!root){
		return;
	}
	stack <Node*> S;
	while(1){
		while(root){
			S.push(root);
			root = root->left;
		}
		if(S.empty()){
			break;
		}

		root = S.top();
		S.pop();
		cout<<root->data<<" ";
		root = root->right;

	}
}

int main(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	inorderIterative(root);

	return 0;
}