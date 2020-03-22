// Seection sort 


#include<iostream>
using namespace std;


void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int arr[] = {2,8,12,17,5,9,1};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting"<<endl;
    for(int i = 0; i < length;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i < length-1; i++ )
    {
        int min = i;
        for(int j = i+1; j < length; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(&arr[i],&arr[min]);
    }


    cout<<"After Sorting"<<endl;
    for(int i = 0; i < length;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}