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

// Recursive function to print preorder

void preorderRecursive(Node* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preorderRecursive(root);

    return 0;
}
