#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[] , int low , int mid , int high){

    int size1 = mid - low + 1;
    int size2 = high - mid;
    int firstArray[size1];
    int secondArray[size2];

    for(int i = 0; i < size1; i++){
        firstArray[i] = arr[low+i];
    }

    for(int i = 0; i < size2; i++){
        secondArray[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;
    while(i < size1 && j < size2){
        if(firstArray[i] < secondArray[j]){
            arr[k] = firstArray[i];
            k++;
            i++;
        }
        else{
            arr[k] = secondArray[j];
            k++;
            j++;
        }
    }

    while(i < size1){
        arr[k] = firstArray[i];
        k++;
        i++;
    }
    while(j < size2){
        arr[k] = secondArray[j];
        k++;
        j++;
    }

}

void mergeSort(int arr[] , int low , int high){

    if(low < high){
        
        int mid = low + (high - low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr,0,arrSize - 1);

    printArray(arr,arrSize);
    

    return 0;
}