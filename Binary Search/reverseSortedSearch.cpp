#include<iostream>
using namespace std;

// [5 , 4 , 3 , 2 , 1]
/*
low = 0 high = len - 1

*/
int reversedBinarySearch(int arr[],int len,int key){
	int low = 0;
	int high = len -1;

	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] > key){
			low = mid + 1;
		}
		else if(arr[mid] < key){
			high = mid - 1;
		}
	}

	return -1;
}


int main(){

	int arr[1000];
	int arr_size, key;
	cout<<"Enter the size of array "<<endl;
	cin>>arr_size;

	cout<<"Enter the elements of the array in descending order"<<endl;

	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter the element to be searched"<<endl;
	cin>>key;

	int searchedResult = reversedBinarySearch(arr,arr_size,key);

	if(searchedResult != -1){
		cout<<"Element found at index : "<<searchedResult<<endl;
	}
	else{
		cout<<"Element not found "<<endl;
	}

	return 0;




}