#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

void pushNode(Node* &head,int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(data);

}

bool areIdentical(Node* a,Node* b){
    if(a == NULL && b == NULL){
        return true;
    }
    if(a != NULL && b != NULL){
        return (a->data == b->data) && areIdentical(a->next,b->next);
    }
    return false;
}

bool areIdenticalIter(Node* a ,Node* b){
    while(a != NULL && b != NULL){
        if(a->data != b->data){
            return false;
        }
        else{
            a = a->next;
            b = b->next;
        }
    }
    return (a == NULL && b == NULL);
}

int main(){

    Node* a = NULL;
    Node* b = NULL;

    cout<<"Enter the element of the first linkdlist"<<endl;
    cout<<"Enter -1 to end the insertion"<<endl;
    while(1){
        int data;
        cin>>data;
        if(data == -1){
            break;
        }
        else{
            pushNode(a,data);
        }
    }

    cout<<"Enter the element of the second linkdlist"<<endl;
    cout<<"Enter -1 to end the insertion"<<endl;
    while(1){
        int data;
        cin>>data;
        if(data == -1){
            break;
        }
        else{
            pushNode(b,data);
        }
    }
    
    //bool result = areIdentical(a,b);
    bool result = areIdenticalIter(a,b);

    if(result){
        cout<<"Linked lists are identical"<<endl;
    }
    else{
        cout<<"Not identical"<<endl;
    }

    return 0;
}