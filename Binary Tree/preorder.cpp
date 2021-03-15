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

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    Node* root;
    root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(9);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    preorder(root);

    return 0;
}