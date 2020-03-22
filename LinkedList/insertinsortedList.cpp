#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void Display(struct Node *ptr)
{
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void InsertSorted(struct Node *p ,int x)
{
    struct Node *temp,*q = NULL;
    temp = new struct Node();
    temp ->data = x;
    temp->next = NULL;
    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp; 
        }
        


    }
    
}


void insertion(int x)
{
    struct Node *temp,*last;
    temp = new struct Node();
    temp->data = x;
    temp->next = NULL;

    if(first == NULL)
    {
        first = temp;
        last = temp;

    }
    else
    {
        last->next = temp;
        last = temp;  
    }
    

    
}

int main()
{

    insertion(1);
    insertion(2);
    insertion(3);
    insertion(4);
    insertion(5);
    insertion(12);

    InsertSorted(first,0);
    InsertSorted(first,9);


    Display(first);



    return 0;
}