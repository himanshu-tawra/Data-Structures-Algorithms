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

bool isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p != NULL)
    {
        if(p ->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{

    insertion(1);
    insertion(2);
    insertion(3);
    insertion(22);
    insertion(5);
    insertion(6);

    Display(first);

    if(isSorted(first) == true)
    {
        cout<<"List is sorted"<<endl;
    }
    else
    {
        cout<<"List is not sorted"<<endl;
    }
    



    return 0;
}