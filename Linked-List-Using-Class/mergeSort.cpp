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


Node *mergeSortedLinkedList(Node * h1,Node * h2)
{
    if(h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }

    Node *newhead;
    
    if(h1->data < h2->data)
    {
        newhead = h1;
        newhead->next = mergeSortedLinkedList(h1->next,h2);
    }
    else
    {
        newhead = h2;
        newhead->next = mergeSortedLinkedList(h1,h2->next);
    }

    return newhead;
    
}


Node *mergeSort(Node *head)
{
    // base case

    if(head == NULL || head->next == NULL)
    {
        return head;
    }


    // recursive case

    //1. Divide
    Node *middle = middleElement(head);
    Node *a = head;
    Node *b = middle->next;
    middle->next = NULL;

    //2.Sort

    a = mergeSort(a);
    b = mergeSort(b);
   
   
    //3.Merge

    Node *newHead = mergeSortedLinkedList(a,b);

    return newHead;

}


int main()
{
    Node *head = NULL;
    for(int i = 0; i < 10; i++)
    {
        insertionAtFront(head,i);
    }

    cout<<"Before Sorting"<<endl;

    displayLinkedList(head);

    Node *sortedListHead = mergeSort(head);
    cout<<"After sorting"<<endl;

    displayLinkedList(sortedListHead);

    return 0;
}