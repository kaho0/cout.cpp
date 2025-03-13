#include<iostream>
#include<vector>
using namespace std;
vector<int>searchRange(vector<int>&nums,int target){
    vector<int>result={-1,-1};
    int left=0,right=nums.size()-1;
    while(left<=right){
       int mid=left+(right-left)/2;
       if(nums[mid]==target){
            result[0]=mid;
            right=mid-1;
       }
       else if(nums[mid]<target){
            left=mid+1;
       }
       else{
            right=mid-1;
       }
    }
    int left2=0,right2=nums.size()-1;
    while(left2<=right2){
       int mid=left2+(right2-left2)/2;
       if(nums[mid]==target){
            result[1]=mid;
            left2 = mid + 1;
       }
       else if(nums[mid]<target){
            left2=mid+1;
       }
       else{
            right2=mid-1;
       }
    }
    return result;
}
int main(){
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;  // Output: [3, 4]
    return 0;
}