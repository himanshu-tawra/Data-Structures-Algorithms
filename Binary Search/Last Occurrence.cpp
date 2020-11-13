#include <iostream>
using namespace std;

int lastOccurrence(int arr[],int len,int key){
	int low = 0;
	int high = len - 1;
	int result = -1;
	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] == key){
			result = mid;
			low = mid + 1; 
		}
		else if(arr[mid] < key){
			low = mid + 1;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
	}
	return result;
}


int main(){

	int arr_size,arr[1000],key;

	cout<<"Enter the size of array"<<endl;
	cin>>arr_size;
	cout<<"Enter the elements of array in ascending order"<<endl;
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter the element to get the index of last occurrence "<<endl;
	cin>>key;

	int result = lastOccurrence(arr,arr_size,key);

	if(result == -1){
		cout<<"Element not found"<<endl;
	}
	else{
		cout<<"Last occurrence of the "<<key<<" is at index : "<<result<<endl;
	}

	return 0;
}