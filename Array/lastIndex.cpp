/*
    Problem:
    Take as input N, the size of array. 
    Take N more inputs and store that in an array. 
    Take as input M, a number. 
    Write a recursive function which returns the last index at which M is found in the array 
    and -1 if M is not found anywhere. 
    Print the value returned.

*/

#include<iostream>
using namespace std;

void findkey(int *a,int key,int i,int n,int j){
    
    if(i==n){
        cout<<j;
        return ;
    }
    
    if(a[i]==key){
        j=i;
        
    }
    
    findkey(a,key,i+1,n,j);
    
}
int main() {

int n;
cin>>n;
int a[n];

for(int i=0;i<n;i++){
    cin>>a[i];
}
int key;
cin>>key;

findkey(a,key,0,n,-1);

	
}