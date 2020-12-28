/*
Program to cyclically rotate an array by one
*/

#include<iostream>
using namespace std;


void printArray(int arr[],int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void rotateCyclic(int arr[],int n){
	int temp = arr[n - 1];

	for(int i = n-1; i > 0; i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}




int main(){
	int arr[1000];
	
	int arr_size;
	
	cout<<"Enter size of array"<<endl;
	
	cin>>arr_size;

	cout<<"Enter elements of array"<<endl;
	
	for(int i = 0; i < arr_size; i++){
		cin>>arr[i];
	}

	printArray(arr,arr_size);

	rotateCyclic(arr,arr_size);
	
	printArray(arr,arr_size);



	return 0;
}