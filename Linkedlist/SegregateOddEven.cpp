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


void pushBack(Node* &head,int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(data);
}


void printLinkedlist(Node* head){
    while (head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


void segregateOddEven(Node* &head){
    Node* evenHead = NULL;
    Node* evenEnd = NULL;
    Node* oddHead = NULL;
    Node* oddEnd = NULL;

    Node* current = head;
    while(current){
        int val = current->data;
        if(val % 2 == 0){
            if(evenHead == NULL){
                evenHead = current;
                evenEnd = evenHead;
            }
            else{
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        }
        else{
            if(oddHead == NULL){
                oddHead = current;
                oddEnd = oddHead;
            }
            else{
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
        }
        current = current->next;
    }
    if(oddHead == NULL || evenHead == NULL){
        return;
    }
    evenEnd->next = oddHead;
    oddEnd->next = NULL;
    head = evenHead;
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
            pushBack(head,data);
        }
    }

    segregateOddEven(head);
    printLinkedlist(head);

    return 0;
}