#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int>&nums,int target,int index=0){
    if(index==nums.size())return -1;
    if(nums[index]==target)return index;
    return firstOccur(nums,target,index+1);
}
int lastOccur(vector<int>&nums,int target,int index){
    if(index==nums.size())return -1;
    if(nums[index]==target)return index;
    return firstOccur(nums,target,index-1);
}
int main(){
    vector<int>nums={1,2,3,4,3,5,6,7,3,4};
    int target;
    cin>>target;
    int firstIndex=firstOccur(nums,target);
    int lastIndex=lastOccur(nums,target,nums.size()-1);
    cout<<firstIndex<<"   "<<lastIndex<<endl;
}