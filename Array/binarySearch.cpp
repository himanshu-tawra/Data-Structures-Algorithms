// Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[],int startIndex,int endIndex,int key){
    
    while(startIndex <= endIndex){
        int midIndex = startIndex + (endIndex - startIndex)/2;
        
        if(arr[midIndex] == key){
            return midIndex;
        }
        else if(arr[midIndex] < key){
            startIndex = midIndex + 1;
        }
        else{
            endIndex = midIndex - 1;
        }
    }
    
    return -1;
}


int main(){
    
    
    int arr[] = {1,2,3,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 1;

    int result = binarySearch(arr,0,n-1,key);
    
    if(result == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Element present at index "<<result<<endl;
    }
    
    return 0;
}
