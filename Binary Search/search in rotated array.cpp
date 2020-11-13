#include <iostream>
using namespace std;

// [5 6 7 1 2 3 4]


int findMin(int arr[],int len){
	int low = 0;
	int high = len - 1;

	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]){
			return mid;
		}
		else if(arr[mid] > arr[high]){
			low = mid + 1;
		}
		else if(arr[mid] > arr[low]){
			high = mid - 1;			
		}
	}
	return -1;

}


int searchInRotatedArray(int arr[],int len,int key){

	if(len == 1){
		if(arr[0] == key){
			return 0;
		}
		else{
			return -1;
		}
	}

	int min = findMin(arr,len);


	int low = 0;
	int high = len - 1;

	if(arr[min] == key){
		return min;
	}
	else if(key > arr[min] && key <= arr[high]){
		low = min;
	}
	else{
		high = min - 1;
	}

	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] < key){
			low = mid + 1;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		
	}
	return -1;
}

int main(){

	int arr[1000],arr_size,key;

	cout<<"Enter the size of array"<<endl;
	cin>>arr_size;

	cout<<"Enter the elements of the array"<<endl;
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter the element to be searched"<<endl;
	cin>>key;

	int search = searchInRotatedArray(arr,arr_size,key);
	if(search != -1){
		cout<<"Element found at index : "<<search<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}

	



	return 0;
}