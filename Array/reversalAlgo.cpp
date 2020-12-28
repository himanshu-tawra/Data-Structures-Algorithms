/*
Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements. 
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[],int low,int high){
	while(low < high){
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;
		high--;
	}
}

void rotateArray(int arr[],int d,int n){

	d = d%n;

	reverseArray(arr,0,d-1);
	reverseArray(arr,d,n-1);
	reverseArray(arr,0,n-1);
}

void printArray(int arr[],int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){

	int arr[1000];
	
	int arr_size;
	
	cin>>arr_size;

	for (int i = 0; i < arr_size; ++i){
		
		cin>>arr[i];
	
	}
	
	int d;
	
	cin>>d;
	
	printArray(arr,arr_size);

	rotateArray(arr,d,arr_size);
	
	printArray(arr,arr_size);




	return 0;
}