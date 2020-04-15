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
    if(root == NULL){
        return;
    }

    queue<Node*> q;

    Node* curr;

    q.push(root);
    q.push(NULL);
    
    while(q.size() > 1){
        curr = q.front();
        q.pop();

        if(curr == NULL){
            q.push(NULL);
            cout<<endl;
        }
        else{
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            cout<<curr->data<<" ";
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

    levelOrder(root);
    

    return 0;
}

