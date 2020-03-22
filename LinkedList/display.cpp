#include<iostream>
using namespace std;



struct Node
{
    int data;
    struct Node *next;
}*first = NULL; // global pointer that can be directly accessed or can be passed as aparameter


 // Function to create a linked list from the given array

void createList(int arr[] , int len)
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

// Function to display linked list

void Display(struct Node *ptr)
{
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}



int main()
{
    int arr[] = {1,2,6,8,4,5,97,8,1,2,25,14};
    
    int len = sizeof(arr)/sizeof(arr[0]);

    createList(arr,len);

    Display(first);

    return 0;
}

