// program to insert an element in a linked list before the first element or at a given position

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*first = NULL;

int count(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct Node *p,int index,int value)
{
    struct Node *temp;

    if(index < 0 || index > count(p))
    {
        return;
    }

    temp = new struct Node();

    temp->data = value;

    if(index == 0)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        for(int i = 0; i < index-1;i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    





}


void create(int arr[] , int len)
{
    struct Node *temp,*last;
    first = new struct Node(); 
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < len; i++)
    {
        temp = new struct Node();
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void printLinkedList(struct Node *p)
{
    if(p != NULL)
    {
        
        cout<<p->data<<" "; 
        printLinkedList(p->next);
    }
}


int main()
{

    insert(first,0,10);
    insert(first,1,20);
    insert(first,2,30);
    insert(first,0,5);
    insert(first,3,40);

    printLinkedList(first);

    cout<<endl;



    return 0;
}