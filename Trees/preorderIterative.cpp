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


void preorderIterative(Node* root){
    if(root == NULL){
        return;
    }
    stack <Node* > s;

    s.push(root);
    Node* curr = root;
    while(!s.empty()){
        if(curr!= NULL){
            cout<<curr->data<<" ";
            if(curr->right){
                s.push(curr->right);
            }
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
        }
    }
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

    preorderIterative(root);

    return 0;
}