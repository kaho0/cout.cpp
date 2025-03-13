#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class solution{
    public:
    bool containsDuplicate(vector<int> &nums){
        unordered_set<int>seen;
        for(int num:nums){
            if(seen.count(num)){
            return true;}
        
        seen.insert(num);
    }
    return false;
    }
};

int main(){
    solution solution;
    vector<int>nums1={1,2,3,1,4,5};
    vector<int>nums2={4,2,3,5};
    cout<<solution.containsDuplicate(nums1)<<endl;
    cout<<solution.containsDuplicate(nums2)<<endl;
}