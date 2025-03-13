#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>find_nums(vector<int>&nums){
    int n=nums.size();
    vector<int>count(n+1,0);
    vector<int> duplicates;
        vector<int> missing;
        
    for(int num:nums){
        count[num]++;

    }
    for(int i=1;i<=n;i++){
        if(count[i]==2) duplicates.push_back(i);
        if(count[i]==0)missing.push_back(i);

    }
    return{duplicates,missing};
}
int main(){
    vector<int>nums={1,2,3,4,4,5,6,6,9};
    vector<vector<int>> result=find_nums(nums);
     cout << "Duplicates: ";
    for (int num : result[0]) {
        cout << num << " ";
    }

    cout << "\nMissing: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}