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

int heightRecursive(Node* head){
    if(head == NULL){
        return 0;
    }

    return 1 + max(heightRecursive(head->left),heightRecursive(head->right));
}

int main(){

    Node* head1 = new Node(1);
    head1->left = new Node(3);
    head1->left->left = new Node(4);
    head1->left->right = new Node(6);
    head1->right = new Node(2);
    head1->right->left = new Node(5);
    head1->right->right = new Node(7);

    cout<<"Height of binary tree : "<<heightRecursive(head1)<<endl;

    return 0;
}