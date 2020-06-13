/*
    Program to left rotate array by k elements
*/

#include<iostream>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseArray(int * arr,int i,int j){
    
    while(i < j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void rotateArray(int *arr,int len,int k){
    k = k%len;

    reverseArray(arr,0,k-1);
    reverseArray(arr,k,len-1);
    reverseArray(arr,0,len-1);

}

void printArray(int *arr,int len){
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[1000];
    int arrSize;
    cin>>arrSize;

    for(int i = 0; i < arrSize; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    rotateArray(arr,arrSize,k);

    printArray(arr,arrSize);


    return 0;
}