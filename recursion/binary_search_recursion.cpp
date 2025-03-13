#include<stdio.h>
#include<iostream>
using namespace std;
int binary_search(int arr[],int left,int right,int target){
    if(left>right)return -1;

     int mid=left+(right-left)/2;

     if(arr[mid]==target) return mid;
     if(arr[mid]>target){
     return(binary_search(arr,left,mid-1,target));
     }
     else{
        return(binary_search(arr,mid+1,right,target));
     }

}
int main(){
    int arr[]={1,2,3,4,5,6,7,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;
    cin>>target;
    int result = binary_search(arr, 0, n-1, target);
    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;

}
