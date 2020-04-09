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

bool isIdentical(Node* head1 , Node* head2){
    if(head1 == NULL && head2 == NULL){
        return true;
    }
    if(head1 == NULL || head2 == NULL){
        return false;
    }

    queue <Node*> q1 , q2;

    q1.push(head1);
    q2.push(head2);

    while (!q1.empty() && !q2.empty()){
        Node* n1 = q1.front();
        Node* n2 = q2.front();

        if(n1->data != n2->data){
            return false;
        }

        q1.pop();
        q2.pop();

        if(n1->left && n2->left){
            q1.push(n1->left);
            q2.push(n2->left);
        }
        else if(n1->left || n2->left){
            return false;
        }

        if(n1->right && n2->right){
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if(n1->right || n2->right){
            return false;
        }
    }
    
    return true;

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
    head2->right->right = new Node(0);


    bool id = isIdentical(head1,head2);

    if(id == true){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Not identical"<<endl;
    }
    
    return 0;
}