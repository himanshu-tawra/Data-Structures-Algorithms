/*
    Bubble sort algorithm
*/
#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int arrSize){
    for(int i = 0; i < arrSize - 1; i++){
        for(int j = 0; j < arrSize - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArray(int arr[] , int arrSize){
    for(int i = 0 ; i < arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){

    int arr[100];
    int arrSize;
    cin>>arrSize;

    for(int i = 0; i < arrSize; i++){
        cin>>arr[i];
    }

    bubbleSort(arr,arrSize);

    printArray(arr,arrSize);

    return 0;
}