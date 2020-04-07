#include<iostream>
using namespace std;

int partition(int *arr,int start,int end){
    int pivot = arr[end];
    int partitionIndex = start;
    for(int i = start; i < end; i++){
        if(arr[i] <= pivot){
            swap(arr[i] , arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex] , arr[end]);
    return partitionIndex;
}


void quickSort(int *arr,int start,int end){
    if(start < end){
        int partitionIndex = partition(arr,start,end);
        quickSort(arr,start,partitionIndex-1);
        quickSort(arr,partitionIndex+1,end);
    }
}

void printArray(int arr[] , int len){
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {7,6,5,4,3,2,1,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting"<<endl;
    printArray(arr,len);
    quickSort(arr,0,len);
    cout<<"Array after sorting"<<endl;
    printArray(arr,len);
    return 0;


}