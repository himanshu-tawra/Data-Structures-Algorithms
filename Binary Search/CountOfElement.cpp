#include <iostream>
using namespace std;


int firstOccurrence(int arr[],int len,int key){
	int low = 0;
	int high =  len - 1;
	int result = -1;

	while(low <= high){
		int mid = low + (high - low)/2;

		if(arr[mid] == key){
			result = mid;
			high = mid - 1;
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

int lastOccurrence(int arr[],int len,int key){
	int low = 0;
	int high =  len - 1;
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

	int arr[1000],arr_size,key;

	cout<<"Enter the size of the array"<<endl;
	cin>>arr_size;

	cout<<"Enter the elements in the array"<<endl;
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter an element to get the count of its occurrence"<<endl;
	cin>>key;

	int first = firstOccurrence(arr,arr_size,key);
	int last  = lastOccurrence(arr,arr_size,key);

	
	if(first == -1){
		cout<<"Element not found "<<endl;
	}
	else{
		int answer = last - first + 1;

		cout<<"Count of "<<key<<" : "<<answer<<endl;
	}

	return 0;
}