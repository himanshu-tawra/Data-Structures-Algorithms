// program to print reverse display using recursion

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;


// recursive function

int maxEle(struct Node *p)
{
    int max = 0;

    if(p == NULL)
    {
        return INT32_MIN;
    }
    else
    {
        max = maxEle(p->next);
        if(max > p->data)
        {
            return max;
        }
        else
        {
            return p->data;
        }
        
    }
    
}



// iterative function
int maxElement(struct Node *p)
{
    int max = INT32_MIN;
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
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

    cout<<"Maximum element (iterative function) : "<<maxElement(first)<<endl;;

    cout<<"Maximum element (Recursive function) : "<<maxEle(first);

    cout<<endl;

    return 0;
}