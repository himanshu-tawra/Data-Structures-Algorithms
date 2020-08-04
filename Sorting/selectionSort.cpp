/* 
Sort the given array using Selection sort.
Time Complexity : O(n^2)
Written by      : Himanshu Tawra
Date            : 07/April/2020
*/

#include<iostream>
using namespace std;


void selectionSort(int *arr,int len){
    int i,j,k;
    for(int i = 0; i < len - 1; i++){
        for(j = k = i; j < len; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        swap(arr[i],arr[k]);
    }
}


void printArray(int arr[],int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[] = {9,12,47,6,5,29,35,14,21};
    
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting"<<endl;
    printArray(arr,arrSize);

    selectionSort(arr,arrSize);

    cout<<"Array after sorting"<<endl;
    printArray(arr,arrSize);    

    return 0;
}