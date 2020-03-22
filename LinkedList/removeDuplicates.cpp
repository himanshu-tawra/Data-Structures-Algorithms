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


void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete(q);
            q = p->next;
        }
        
    }
}

int main()
{

    insertion(1);
    insertion(1);
    insertion(2);
    insertion(2);
    insertion(3);
    insertion(3);

    removeDuplicates(first);
    Display(first);

    


    return 0;
}