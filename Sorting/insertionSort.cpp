/*
Sort the array using insertion sort.
	Time complexity:
	Best case  : O(n)
	Worst Case : O(n^2)
	Written by : Himanshu Tawra
	Date 	   : 07/April/2020  
*/

#include<iostream>
using namespace std;

void insertionSort(int *arr,int len){

	for(int i = 1; i < len; i++){
		int j = i - 1;
		int x = arr[i];
		while(j >=0 && arr[j] > arr[j+1]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;

	}

}


void printArray(int arr[],int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

	int arr[] = {9,12,47,6,5,29,35,14,21};
    
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting"<<endl;
    printArray(arr,arrSize);

    insertionSort(arr,arrSize);

    cout<<"Array after sorting"<<endl;
    printArray(arr,arrSize); 

	return 0;
}