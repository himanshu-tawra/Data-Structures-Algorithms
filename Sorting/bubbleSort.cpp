// Program for bubble sort

#include<iostream>
using namespace std;

int main()
{
    int arr[] = { 8,5,12,21,14,77,5};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before swapping"<<endl;

    for(int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(arr[j+1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    cout<<"After swapping"<<endl;

    for(int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;

}