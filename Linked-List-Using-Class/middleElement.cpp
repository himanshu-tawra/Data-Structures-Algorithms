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

Node* middleElement(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


void insertionAtFront(Node * &head,int data)
{
    if(head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp ->next = head;
        head = temp;
    }   
}

void Display(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{   
    Node *head = NULL;

    for(int i = 1; i <= 5; i++)
    {
        insertionAtFront(head,i);
    }

    Display(head);

    Node *ans = middleElement(head);
    cout<<"Middle element : "<<ans->data<<endl;

    return 0;
}