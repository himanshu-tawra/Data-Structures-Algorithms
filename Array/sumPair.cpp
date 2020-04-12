// Time complexity O(n)

#include<iostream>
#include<unordered_map>
using namespace std;

void findPair(int arr[] , int len, int sum){
    unordered_map<int ,int> map;

    for(int i = 0; i < len; i++){
        if(map.find(sum-arr[i]) != map.end()){
            cout<<"pair found at index "<<map[sum-arr[i]]<<" and "<<i;
            return;
        }
        map[arr[i]] = i;
    }
    cout<<"Pair not found"<<endl;
    
}

int main(){
    // Find pair with given sum in the array

	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;
 
	int n = sizeof(arr)/sizeof(arr[0]);
 
	findPair(arr, n, sum);


    return 0;
}