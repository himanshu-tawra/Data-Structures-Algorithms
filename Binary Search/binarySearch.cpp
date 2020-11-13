#include<iostream>
using namespace std;

int binarySearch(int arr[],int len,int key){
    int low = arr[0];
    int high = arr[len- 1];
    while(low <= high){
    	int mid = low + (high - low)/2;

    	if(arr[mid] == key){
    		return mid;
    	}
    	else if(arr[mid] > key){
    		high = mid - 1;
    	}
    	else{
    		low = mid + 1;
    	}
    }

    return -1;

}




int main(){


	int arr[1000];
	int arr_size;
	cout<<"Enter the size of the array "<<endl;
	cin>>arr_size;

	cout<<"Enter the elements of array "<<endl;

	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter the element to be searched "<<endl;
	int key;
	cin>>key;

	int midIndex = binarySearch(arr,arr_size,key);

	if(midIndex != -1){
		cout<<"Element found at index : "<<midIndex<<endl;
	}
	else{
		cout<<"Element not found "<<endl;
	}


    return 0;
}