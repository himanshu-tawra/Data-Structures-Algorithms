// program to print reverse display using recursion

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;


struct Node *search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if((p->data) == key)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

void printLinkedList(struct Node *p)
{
    if(p != NULL)
    {
        
        cout<<p->data<<" "; 
        printLinkedList(p->next);
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



int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    
    int length = sizeof(arr)/sizeof(arr[0]);

    create(arr,length);

    printLinkedList(first);

    cout<<endl;

    cout<<"Enter the element to be  searched"<<endl;
    int key;
    cin>>key;

    struct Node *temp;
    temp = search(first,key);

    if(temp)
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    

    return 0;
}