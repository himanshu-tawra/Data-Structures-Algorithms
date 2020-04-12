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

void postOrderRecursive(Node* root){
    if(root == NULL){
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout<<root->data<<" ";
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

    postOrderRecursive(root);
    cout<<endl;

    return 0;
}