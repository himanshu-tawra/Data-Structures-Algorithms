//floyd_Cycle_Loop_Detection

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

void insertionAtFront(Node* &head,int element)
{
    if(head == NULL)
    {
        head = new Node(element);
        return;
    }

    Node* temp = new Node(element);
    temp->next = head;
    head = temp;

}

void displayLinkedlist(Node* head)
{
    if(head == NULL)
    {
        cout<<"Linkedlist is empty..!!"<<endl;
        return;
    }
    cout<<"Created Linkedlist "<<endl;
    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int countNodes(Node* n)
{
    int result = 1;
    Node* temp = n;
    while(temp->next != n)
    {
        result++;
        temp = temp->next;
    }
    return result;
}

//This function uses two pointer- one is slow and the other is fast.

int detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return countNodes(slow);
        }
    }
    return 0;
}


int main()
{
    Node* head;

    insertionAtFront(head,1);
    insertionAtFront(head,8);
    insertionAtFront(head,1);
    insertionAtFront(head,4);
    insertionAtFront(head,1);
    insertionAtFront(head,1);

    head->next->next->next->next->next->next = head->next;

    int loopLength = detectLoop(head);

    
    cout<<loopLength<<endl;
        
    
   
    
    return 0;
}