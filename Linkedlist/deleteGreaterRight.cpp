/*
Problem : Delete nodes which have a gtrater value on right side
*/

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


void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverseLinkedlist(Node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* previous = NULL;
    Node* current = head;
    while(current){
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    head = previous;
}

void deleteSmaller(Node* &head){
    if(head == NULL){
        return;
    }
    Node* current = head;
    Node* max = head;
    Node* temp = NULL;
    while(current && current->next){
        if(current->next->data < max->data){
            temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else{
            current = current->next;
            max = current;
        }
    }
}

int main(){

    Node* head = NULL;

    cout<<"Enter elements in linkedlist"<<endl;
    cout<<"To end insertion enter -1"<<endl;
    while (1)
    {
        int data;
        cin>>data;
        if(data == -1){
            break;
        }
        else{
            pushNode(head,data);
        }
    }
    
    printList(head);
    reverseLinkedlist(head);
    deleteSmaller(head);
    reverseLinkedlist(head);
    printList(head);
    

    return 0;
}