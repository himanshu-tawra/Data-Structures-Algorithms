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

void inorderRecursive(Node* root){
   if(root == NULL){
       return;
   }
   inorderRecursive(root->left);
   cout<<root->data<<" ";
   inorderRecursive(root->right);
}




int main(){

    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);


    inorderRecursive(root);

    return 0;
}