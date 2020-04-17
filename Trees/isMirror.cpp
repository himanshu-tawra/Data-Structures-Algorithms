#include<iostream>
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

bool isMirror(Node* a,Node* b){
    if(a == NULL && b == NULL){
        return true;
    } 
    if(a == NULL || b == NULL){
        return false;
    }
    if(a->data == b->data){
        if(isMirror(a->left,b->right) && isMirror(a->right,b->left)){
            return true;
        }
    }
    return false;
}

int main(){

    Node *a = new Node(1); 
    Node *b = new Node(1); 
    a->left = new Node(2); 
    a->right = new Node(3); 
    a->left->left  = new Node(4); 
    a->left->right = new Node(5); 
  
    b->left = new Node(3); 
    b->right = new Node(2); 
    b->right->left = new Node(5); 
    b->right->right = new Node(4); 

    if(isMirror(a,b)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    


    return 0;
}