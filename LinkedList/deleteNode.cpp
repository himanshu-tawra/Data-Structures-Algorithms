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

int Delete(struct Node *p,int index)
{
    struct Node *q = NULL;
    int x = -1;

    if(index < 1 || index > count(p))
    {
        return -1;
    }
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete(q);
        return x;
    }
    else
    {
        for(int i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete(p);
        return x;
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
    insertion(6);
    cout<<"Before deletion"<<endl;
    Display(first);
    Delete(first,1);
    cout<<"After deletion"<<endl;
    Display(first);

    return 0;
}