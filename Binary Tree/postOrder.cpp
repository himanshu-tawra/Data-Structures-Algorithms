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


void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void postOrderIterative(Node* root){

    Node* prev = NULL;
    stack <Node*> s;
    
    do{
        while(root){
            s.push(root);
            root = root->left;
        }

        while(root == NULL && !s.empty()){
            root = s.top();

            if(root->right == NULL || root->right == prev){
                cout<<root->data<<" ";
                s.pop();
                prev = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }
    }while(!s.empty());

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

    postOrder(root);
    cout<<endl;
    postOrderIterative(root);

    return 0;
}