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

void inorderIterative(Node* root){
    stack <Node*> st;
    
    Node* curr = root;

    while(!st.empty() || curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();

            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
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


    inorderIterative(root);

    return 0;
}