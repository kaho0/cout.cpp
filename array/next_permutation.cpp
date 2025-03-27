#include <bits/stdc++.h>
using namespace std;
void nextPerm(vector<int>&nums){
    int n=nums.size();
    int gola_index=-1;
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            gola_index=i-1;
            break;
        }
    }
    if(gola_index==-1){
        reverse(nums.begin(),nums.end());;
    }
    int swap_index=-1;
    for(int j=n-1;j>gola_index;j--){
        if(nums[j]>nums[gola_index]){
            swap_index=j;
            break;
        }
    }
    swap(nums[gola_index],nums[swap_index]);
    reverse(nums.begin()+gola_index+1,nums.end());
}
int main(){
    vector<int>nums={1,2,3};
     cout << "Original array: ";
     for(int num:nums)cout<<num<<" ";
     cout<<endl;
     nextPerm(nums);
     cout << "Next permutation: ";
     for(int num:nums)cout<<num<<" ";
     cout<<endl;

}
