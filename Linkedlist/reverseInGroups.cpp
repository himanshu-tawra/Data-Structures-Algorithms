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

Node* reverseList(Node* &head,int k){
    Node* current = head;
    Node* previous = NULL;
    Node* nextNode = NULL;
    int count = 0;
    while(current && count < k){
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
        count++;
    }

    if(nextNode != NULL){
        head->next = reverseList(nextNode,k);
    }

    return previous;

}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
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
    head = reverseList(head,2);
    printList(head);



    return 0;
}