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

bool isIdentical(Node* head1 , Node* head2){
   if(head1 == NULL && head2 == NULL){
       return true;
   }

   if(head1 != NULL && head2 != NULL){
       return (head1->data == head2->data && isIdentical(head1->left,head2->left) && isIdentical(head1->right,head2->right));
   }
   return false;
}

int main(){

    Node* head1 = new Node(1);
    head1->left = new Node(3);
    head1->left->left = new Node(4);
    head1->left->right = new Node(6);
    head1->right = new Node(2);
    head1->right->left = new Node(5);
    head1->right->right = new Node(7);

    Node* head2 = new Node(1);
    head2->left = new Node(3);
    head2->left->left = new Node(4);
    head2->left->right = new Node(6);
    head2->right = new Node(2);
    head2->right->left = new Node(5);
    head2->right->right = new Node(7);


    bool id = isIdentical(head1,head2);

    if(id == true){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Not identical"<<endl;
    }
    
    return 0;
}