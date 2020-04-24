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

void printNodes(Node* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }
    else{
        printNodes(root->left,k-1);
        printNodes(root->right,k-1);
    }
    
}


int main(){

    /* Constructed binary tree is  
            1  
            / \  
          2     3  
        /  \   /  
       4    5 8  
    */
    Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->left->right = new Node(5);  
    root->right->left = new Node(8);  

    printNodes(root,2);

    return 0;
}