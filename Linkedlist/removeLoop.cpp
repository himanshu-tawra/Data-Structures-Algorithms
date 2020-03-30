#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
};


void deleteLoop(Node* head,Node* fast)
{
    Node* p = fast;
    Node* q = fast;

    //length of node
    int k = 1;
    while(p->next != q)
    {
        k++;
        p = p ->next;
    }

    // fix one pointer to head
    p = head;

    q = head;

    // other pointer to k nodes after head
    for(int i = 0; i < k; i++)
    {
        q = q->next;
    }

    //move both pointers at the same pase till they meet at loop starting node
    while(p != q)
    {
        p = p->next;
        q = q->next;

    }

// get pointer to the last node

    while(q->next != p)
    {
        q = q->next;
    }
// set next to last pointer to NULL

    q->next = NULL;

}
void detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            cout<<"Loop Found"<<endl;
            deleteLoop(head,fast);
            return;
        }

    }
    cout<<"Loop not detected"<<endl;
}

void printLinkedlist(Node* head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{   
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head->next->next;

    detectLoop(head);

    cout<<"After removing loop"<<endl;

    printLinkedlist(head);


}