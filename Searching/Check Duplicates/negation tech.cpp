/*

Problem : Given an array of n numbers. 

Given an algorithm for checking whether there are any duplicate elements in the array or not?

Time complexity : O(n)

*/

#include<iostream>
#include<algorithm>
using namespace std;

int checkDuplicate(int *arr,int len){
    if(len == 1){
        return -1; 
    }

    for(int i = 0; i < len; i++){
        if(arr[abs(arr[i])] < 0){
            return i;
        }
        else{
            arr[arr[i]] = -arr[arr[i]];
        }
    }

    return -1;

}



int main(){

    int arr[] = {3,2,1,2,2,3};
    int len = sizeof(arr)/sizeof(arr[0]);


    int duplicate = checkDuplicate(arr,len);

    if(duplicate != -1){
        cout<<"Duplicate element found : "<<abs(arr[duplicate])<<endl;
    }
    else{
        cout<<"No duplicate in given array"<<endl;
    }


    return 0;
}