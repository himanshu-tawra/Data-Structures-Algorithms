#include<iostream>
using namespace std;
 
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

void reverseArray(int *arr ,int len){

    int i = 0;
    int j = len-1;

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



int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array"<<endl;
    printArray(arr,len);

    reverseArray(arr,len);

    cout<<"Array after swapping"<<endl;
    printArray(arr,len);
    
    return 0;
}