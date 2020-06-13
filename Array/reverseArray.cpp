#include<iostream>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int reverseArray(int * arr,int len){
    int i = 0;
    int j = len - 1;

    while(i < j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

}

void printArray(int *arr,int len){
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[1000];
    int size;
    cin>>size;

    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    reverseArray(arr,size);
    printArray(arr,size);


    return 0;
}