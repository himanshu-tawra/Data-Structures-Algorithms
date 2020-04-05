// Reversal Algorithm to reverse an array d times leftward

#include<iostream>
using namespace std;
 
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

void reverseArray(int *arr ,int i,int j){
    while(i < j){
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

void printArray(int *arr, int len){
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rotateArray(int *arr,int d,int len){
    reverseArray(arr,0,d-1);
    reverseArray(arr,d,len-1);
    reverseArray(arr,0,len-1);
}



int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    int d = 3;
    d = d % len;
    printArray(arr,len);
    rotateArray(arr,d,len);
    printArray(arr,len);

    
    return 0;
}