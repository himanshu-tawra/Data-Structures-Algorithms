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

int findMax(Node* root){
    int rootValue,left,right,max = INT_MIN;

    if(root == NULL){
        return 0;
    }
    rootValue = root->data;
    left = findMax(root->left);
    right = findMax(root->right);

    if(left > right){
        max = left;
    }
    else{
        max = right;
    }
    if(max > rootValue){
        return max;
    }
    else{
        return rootValue;
    }

}

int findMaxIterative(Node* root){
    int max = INT_MIN;
    Node* temp;

    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data > max){
            max = temp->data;
        }

        if(temp->left){
            q.push(temp->left);
        }
        
        if(temp->right){
            q.push(temp->right);
        }

    }

    return max;


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

    int maxNode = findMax(root);

    cout<<maxNode<<endl;

    
    int maxIter = findMaxIterative(root);

    cout<<maxIter<<endl;

    return 0;
}