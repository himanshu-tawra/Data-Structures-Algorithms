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

bool recursiveSearch(Node* root,int key){

    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }
    
    bool left = recursiveSearch(root->left,key);
    if(left == true){
        return true;
    }
    else{
        return recursiveSearch(root->right,key);
    }

    return false;
}

bool iterativeSearch(Node* root,int key){

    queue <Node*> q;

    Node* temp;

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == key){
            return true;
        }
        else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    return false;
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

    bool searchNode = recursiveSearch(root,5);

    if(searchNode){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    
    bool searchIterativeNode = iterativeSearch(root,15);

    if(searchIterativeNode){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    return 0;
}