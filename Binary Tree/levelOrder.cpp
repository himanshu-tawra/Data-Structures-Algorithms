#include<iostream>
#include<queue>
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

void levelOrder(Node* root){
    queue <Node*> q;

    Node* temp;
    if(!root){
        return;
    }

    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
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

    levelOrder(root);

    return 0;
}