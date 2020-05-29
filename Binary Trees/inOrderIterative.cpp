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


void inOrder(Node* root){
    Node* current = root;
    stack <Node*> stk;
    
    while(1){

        while(current){
            stk.push(current);        
            current = current->left;
        }

        if(stk.empty()){
            break;
        }

        current = stk.top();
        stk.pop();
        cout<<current->data<<" ";
        current = current->right;
    }
    cout<<endl;

}

Node* createBT(){

    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    root->left = createBT();
    root->right = createBT();

    return root;
}


int main(){

    Node* root = createBT();

    inOrder(root);


    return 0;
}