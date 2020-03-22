// program to print reverse display using recursion

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;


void printReverse(struct Node *p)
{
    if(p != NULL)
    {
        printReverse(p->next);
        cout<<p->data<<" "; // printing at returing time
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

    printReverse(first);
    cout<<endl;

    return 0;
}