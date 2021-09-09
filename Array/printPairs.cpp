// Print all pairs

#include<iostream>
using namespace std;

void printPairs(int arr[],int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
        cout<<endl;
    }
}


int main(){
    
    int arr[] = {1,2,3,4,5,6};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printPairs(arr,n);
    
    
    return 0;
}
