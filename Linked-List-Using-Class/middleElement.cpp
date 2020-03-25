#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertionAtFront(Node * &head,int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
}

void displayLinkedList(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        cout<<head->data<<"-->";
        head = head ->next;
    }
    cout<<"NULL"<<endl;
}


Node *middleElement(Node *head)
{
   
    Node *slow = head;
    Node *fast = head->next;
    if(head != NULL)
    {
        while(fast!= NULL && fast->next!= NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        
        }
    }
    

    return slow;
}


int main()
{
    Node * head = NULL;

    insertionAtFront(head,10);
    insertionAtFront(head,8);
    insertionAtFront(head,5);
    insertionAtFront(head,2);
    insertionAtFront(head,1);

    displayLinkedList(head);

    Node *ans = middleElement(head);

    cout<<"Midle Element : "<<ans->data<<endl;

    return 0;
}