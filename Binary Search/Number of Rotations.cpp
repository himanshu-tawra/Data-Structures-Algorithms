#include <iostream>
using namespace std;

// [3 , 4 , 5 , 1 , 2]


int numberOfRotations(int arr[],int len){
	int low = 0;
	int high = len - 1;

	if(len == 1){
		return 0;
	}
	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]){
			return mid;
		}
		else if(arr[low] > arr[high]){
			low = mid + 1;
		}
		else if(arr[low] < arr[high]){
			high = mid - 1;
		}
	}
	return -1;
}


int main(){

	int arr[1000],arr_size;

	cout<<"Enter the size of array "<<endl;
	cin>>arr_size;

	cout<<"Enter the elements in the rotated sorted array"<<endl;
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	int result = numberOfRotations(arr,arr_size);
	if(result != -1){
		cout<<"Array is rotated by "<<result<<" elements"<<endl;
	}


	return 0;
}