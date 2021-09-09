// Reverse Array

#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[],int n){
    
    int startIndex = 0;
    int endIndex = n - 1;
    
    while(startIndex < endIndex){
        swap(arr[startIndex],arr[endIndex]);
        startIndex++;
        endIndex--;
    }
}


int main(){
    
    
    int arr[] = {1,2,3,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original array "<<endl;
    printArray(arr,n);
    
    cout<<"Reversed array "<<endl;
    reverseArray(arr,n);
    printArray(arr,n);
    
    return 0;
}
