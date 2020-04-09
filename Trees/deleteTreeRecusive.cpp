#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int d){
            data = d;
            right = left = NULL;
        }
};


void deleteTreeRecursive(Node* &root){
    if(root == NULL){
        return;
    }

    deleteTreeRecursive(root->left);
    deleteTreeRecursive(root->right);

    delete root;

    root = NULL;
}
int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    deleteTreeRecursive(root);

    if(root == NULL){
        cout<<"Tree successfully deleted"<<endl;
    }

    return 0;

}