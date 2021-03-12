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

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void inorderIterative(Node* root){

    stack <Node*> s;
    while(1){
        while(root){
            s.push(root);
            root = root->left;
        }

        if(s.empty()){
            break;
        }

        root = s.top();
        s.pop();
        cout<<root->data<<" ";
        root = root->right;
    }

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

    inorder(root);
    cout<<endl;
    inorderIterative(root);
    return 0;
}