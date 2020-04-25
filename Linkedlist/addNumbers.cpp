// Program to add two numbers

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


void reverseLinkedlist(Node* &head){
    Node* current = head;
    Node* previous = NULL;

    while (current)
    {
        Node* currNext = current->next;
        current->next = previous;
        previous = current;
        current = currNext;

    }
    head = previous;
}

void printLinkedlist(Node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int lengthOfLinkedlist(Node* head){
    if(head == NULL){
        return 0;
    }
    return lengthOfLinkedlist(head->next) + 1;
}

void insertZero(Node* &head,int d){
    Node* temp = head;
    for(int i = 0; i < d; i++){
        Node* zero = new Node(0);
        zero->next = temp;
        temp = zero;
    }
    head = temp;

}

Node* addLinkedlist(Node* head1 , Node* head2){

    Node* result ;
    Node* temp;
    Node* previous;

    int carry = 0, sum;

    while(head1 && head2){
        sum = carry + head1->data + head2->data;
        carry = sum / 10;
        sum = sum % 10;
        temp = new Node(sum);

        if(result == NULL){
            result = temp;
        }else
        {
            previous->next = temp;
        }
        previous = temp;
        head1 = head1->next;
        head2 = head2->next;

        
    }
    if(carry > 0){
        temp->next = new Node(carry);
    }
    return result;
   
}

int main(){
    Node* head1 = new Node(2);
    head1->next = new Node(1);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(8);
    head1->next->next->next->next = new Node(9);


    Node* head2 = new Node(1);
    head2->next = new Node(7);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(3);

    int length1 = lengthOfLinkedlist(head1);
    int length2 = lengthOfLinkedlist(head2);

    int diff = abs(length1 - length2);

    if(length1 > length2){
        insertZero(head2,diff);
    }
    else if(length2 > length1){
        insertZero(head1,diff);
    }

    reverseLinkedlist(head1);
    reverseLinkedlist(head2);

    Node* head3 = addLinkedlist(head1,head2);
    
    reverseLinkedlist(head3);

    reverseLinkedlist(head1);
    reverseLinkedlist(head2);
    printLinkedlist(head1);
    printLinkedlist(head2);
    printLinkedlist(head3);
    
    
    return 0;

}
