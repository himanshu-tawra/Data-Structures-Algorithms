#include <iostream>
using namespace std;


int firstOccurrence(int arr[],int len,int key){
	int low = 0;
	int high = len - 1;
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




int main(){

	int arr_size,arr[1000],key;
	cout<<"Enter size of array"<<endl;

	cin>>arr_size;

	cout<<"Enter elements of array in sorted order "<<endl;
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	cout<<"Enter the number to check the index of first occurrence"<<endl;
	cin>>key;

	int result = firstOccurrence(arr,arr_size,key);

	if(result != -1){
		cout<<"First occurrence of "<<key<<" : "<<result<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}




	return 0;
}