/* 
Sort the given array using bubble sort.
Time Complexity : O(n^2)
Written by      : Himanshu Tawra
Date            : 07/April/2020
*/

#include<iostream>
using namespace std;

void bubbleSort(int *arr,int arrSize){
    bool flag;
    for(int i = 0; i < arrSize-1; i++){
        flag = false;
        for(int j = 0; j < arrSize - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            break;
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

    int arr[] = {9,12,47,6,5,29,35,14,21};
    
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting"<<endl;
    printArray(arr,arrSize);

    bubbleSort(arr,arrSize);

    cout<<"Array after sorting"<<endl;
    printArray(arr,arrSize);    

    return 0;
}