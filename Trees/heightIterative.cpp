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

int heightIterative(Node* root){

    if(root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int height = 0;
    Node* frontNode = NULL;

    while(!q.empty()){
        int sizeOfQueue = q.size();

        while(sizeOfQueue){
            frontNode = q.front();
            q.pop();

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }

            sizeOfQueue--;
        }
        height++;
    }
    return height;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"Height of binary tree : "<<heightIterative(root)<<endl;

    return 0;
}