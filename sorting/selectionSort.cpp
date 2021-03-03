/*
    Selection sort algorithm
*/

#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[],int arrSize){
    for(int i = 0; i < arrSize - 1; i++){
        for(int j = i+1; j < arrSize; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void printArray(int arr[],int arrSize){
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

    selectionSort(arr,arrSize);

    printArray(arr,arrSize);
    

    return 0;
}