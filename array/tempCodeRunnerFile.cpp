#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>&height){
    int left=0,right=height.size()-1;
    int max_area=0;
    while(left<right){
        int current_height=min(height[left],height[right]);
        int current_width=right-left;
        int current_area=current_height*current_width;
        max_area=max(max_area,current_area);
        if(height[right]>height[left]){
            left++;
        }
        else right--;
    }
    return max_area;
}
int main(){
  vector<int>height={1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout<<"Max Area : "<<maxArea(height)<<endl;
}