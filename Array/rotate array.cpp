/*
Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements left.


*/

#include <iostream>
using namespace std;

void rotateOne(int arr[],int n){
	int temp = arr[0];
	for(int i = 0; i < n - 1; i++){
		arr[i] = arr[i+1];
	}
	arr[n-1] = temp;
}


void rotate(int arr[],int d,int n){

	for(int i = 0; i < d; i++){
		rotateOne(arr,n);
	}
}

void printArray(int arr[],int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i];
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
	rotate(arr,d,arr_size);
	printArray(arr,arr_size);
	return 0;
}