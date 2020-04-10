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

void deleteTreeIterative(Node* &root){
    if(root == NULL){
        return;
    }
    queue <Node* > q;
    q.push(root);

    Node* front = NULL;
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
        delete front;
    }
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

    deleteTreeIterative(root);
    if(root == NULL){
        cout<<"Tree deleted successfully"<<endl;
    }



    return 0;
}