/*

Problem : Given an array of n numbers. 

Given an algorithm for checking whether there are any duplicate elements in the array or not?

Time complexity : O(n^2)

*/

#include<iostream>
using namespace std;

int checkDuplicate(int *arr,int len){
    if(len == 1){
        return -1; 
    }

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(arr[i] == arr[j]){
                return i;
            }
        }
    }

    return -1;

}



int main(){

    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);


    int duplicate = checkDuplicate(arr,len);

    if(duplicate != -1){
        cout<<"Duplicate element found : "<<arr[duplicate]<<endl;
    }
    else{
        cout<<"No duplicate in given array"<<endl;
    }


    return 0;
}