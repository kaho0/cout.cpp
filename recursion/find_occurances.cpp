#include<iostream>
#include<vector>
using namespace std;
void occurances(int arr[],int n,int key,int index,vector<int>&indices){
    if(index==n)return;
    if(arr[index]==key){
        indices.push_back(index);
    }
    occurances(arr,n,key,index+1,indices);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=2;
    vector<int>indices;
    occurances(arr,n,key,0,indices);
    if(indices.empty()){
        cout<<"Element not found"<<endl;

    }else{
        cout<<"Element "<<key<<"  Found at indices: ";
        for(int index:indices){
            cout<<index<<endl;
        }
    }
}