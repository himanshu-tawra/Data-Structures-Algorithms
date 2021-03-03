/*
    Inseertion Sort Algorithm
*/

#include<iostream>
using namespace std;

void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[] , int arrSize){
    for(int i = 1; i < arrSize; i++){
        int currrent = arr[i];
        int j = i - 1;
        while(arr[j] > currrent && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currrent;
    }
}

void printArray(int arr[] , int arrSize){
    for(int i = 0; i < arrSize; i++){
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

    insertionSort(arr,arrSize);

    printArray(arr,arrSize);
    return 0;
}