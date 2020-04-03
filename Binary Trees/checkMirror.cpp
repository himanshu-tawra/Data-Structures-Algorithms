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
            left = NULL;
            right = NULL;
        }
};

bool checkMirror(Node* x, Node* y){

    if(x == NULL && y == NULL){
        return true;
    }
    if(x == NULL || y == NULL){
        return false;
    }

    bool isLeftTreeMirror = checkMirror(x->left,y->right);
    bool isRightTreeMirror = checkMirror(x->right,y->left);
    if(x->data == y->data && isLeftTreeMirror && isRightTreeMirror){
        return true;
    }
    return false;
}

int main(){


    Node* rootX = new Node(1); 
    rootX->left = new Node(2); 
    rootX->right = new Node(3); 
    rootX->left->left = new Node(4); 
    rootX->left->right = new Node(5); 

    Node* rootY = new Node(1); 
    rootY->left = new Node(3); 
    rootY->right = new Node(2); 
    rootY->right->right = new Node(4); 
    rootY->right->left = new Node(5); 

    bool isMirror = checkMirror(rootX,rootY);

    if(isMirror){
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    



    return 0;
}