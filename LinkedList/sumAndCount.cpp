// program to count the nodes of the linked list and to calculate their sum

#include<iostream>
using namespace std;



struct Node
{
    int data;
    struct Node *next;
}*first = NULL; 


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

// iterative function to find the sum of elements of a linked list

int sum(struct Node *p)
{
    int Lsum = 0;
    while(p != NULL)
    {
        Lsum += p->data;
        p = p->next;
    }
    return Lsum;
}


// recursive function to find the sum of elements of a linked list

int RSum(struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return RSum(p->next) + p->data;
    }
    
}

// iterative function to count the number of elements in a linked list

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

// recursive function to count the number of elements in a linked list

int Rcount(struct Node *p)
{
    int counter = 0;
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return Rcount(p->next) + 1;
    }
    
}

int main()
{
    int arr[] = {1,2,6,8,4,5,97,8,21,47,59};
    
    int len = sizeof(arr)/sizeof(arr[0]);

    createList(arr,len);


    cout<<"Sum by recursive function : "<<RSum(first)<<endl;

    cout<<"Sum by iterative function : "<<sum(first)<<endl;

    cout<<"Total nodes calculated by recursive function : "<<Rcount(first)<<endl;

    cout<<"Total nodes calculated by iterative function : "<<count(first)<<endl;

    return 0;
}

