// Linear Serach 

#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}


int main(){
    
    
    int arr[] = {2,5,1,9,4,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    
    int result = linearSearch(arr,n,key);
    
    if(result == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Element present at index "<<result<<endl;
    }
    
    
    return 0;
}
