/*
    Quick Sort Algorithm
*/

#include<bits\stdc++.h>
using namespace std;

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[] , int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1] , arr[high]);

    return i+1;
}


void quickSort(int arr[] , int low, int high){
    if(low < high){

        int partitionIndex = partition(arr,low,high);

        quickSort(arr,low,partitionIndex - 1);
        quickSort(arr,partitionIndex + 1 , high);
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

    quickSort(arr,0,arrSize - 1);

    printArray(arr,arrSize);

    return 0;
}