// Binary Search Recursive

#include<iostream>
using namespace std;

int binarySearch(int arr[],int startIndex,int endIndex,int key){
    
    if(startIndex > endIndex){
        return -1;
    }
    else{
        int midIndex = startIndex + (endIndex - startIndex)/2;
        if(arr[midIndex] == key){
            return midIndex;
        }
        else if(arr[midIndex] < key){
            return binarySearch(arr,midIndex + 1,endIndex,key);
        }
        else{
            return binarySearch(arr,startIndex,midIndex - 1,key);
        }
    }
    

}


int main(){
    
    
    int arr[] = {1,2,3,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 99;

    int result = binarySearch(arr,0,n-1,key);
    
    if(result == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Element present at index "<<result<<endl;
    }
    
    return 0;
}
