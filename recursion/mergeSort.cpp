#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int si,int mid,int ei){
    vector<int>temp;
    int i=si,j=mid+1;
    while(i<=mid&& j<=ei){
        if(arr[i]<=arr[j]){
 temp.push_back(arr[i++]);

        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    for(int idx=si,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }
}
void mergeSort(int arr[],int si,int ei){
    if(si>=ei)return;
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);

}
int main(){
    int arr[6]={6,4,3,2,1,9};
    int n=6;
    mergeSort(arr,0,n-1);
      cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}