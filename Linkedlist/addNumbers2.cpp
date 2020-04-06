// Program to add two numbers represented by linkedlist using stack

#include<iostream>
#include<stack>
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

void printLinkedlist(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* addNnumbers(Node* head1,Node* head2){

    stack <int> s1,s2;
    while(head1){
        s1.push(head1->data);
        head1 = head1->next;
    }
    while (head2){
        s2.push(head2->data);
        head2 = head2->next;
    }

    int sum = 0;
    Node* result = new Node(0);

    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            sum+= s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum+= s2.top();
            s2.pop();
        }

        result->data = sum % 10;
        Node* head = new Node(sum / 10);
        head->next = result;
        result = head;
        sum = sum / 10;
    }

    if(result->data != 0){
        return result;
    }else{
        return result->next;
    }
    
}



int main(){

    Node* head1 = new Node(7);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(3);


    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* final = addNnumbers(head1,head2);

    printLinkedlist(head1);
    printLinkedlist(head2);
    printLinkedlist(final);



    return 0;
}