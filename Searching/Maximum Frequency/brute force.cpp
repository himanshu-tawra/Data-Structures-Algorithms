/*

Given a array of n numbers. 

Give an algorithm for finding the element which appears the maximum number of times in the array.

Time Complexity : O(n^2)
*/

#include<iostream>
using namespace std;

int maxFreq(int *arr,int len){

    int max = -1;
    int counter = 0;
    int maxElement = -1;

    if(len == 1){
        return arr[0];
    }

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(arr[i] == arr[j]){
                counter++;
            }

        }
        if(counter > max){
            max = counter;
            maxElement = arr[i];
        }
    }

    return maxElement;



}

int main(){

    int arr[] = {1,5,7,5,2,1,7,5,7,7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int maxi = maxFreq(arr,arr_size);

    if(maxi != -1){
        cout<<"Element occurring maximum times : "<<maxi<<endl;
    }
    else{
        cout<<"No element occurring maximum times"<<endl;
    }



 
    return 0;
}