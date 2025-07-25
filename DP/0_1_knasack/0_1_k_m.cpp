#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>val,vector<int>wt,int w,int n,vector<vector<int>>&dp){
    if(n==0||w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
       return dp[n][w];
    }
    int itemWt=wt[n-1];
    int itemVal=val[n-1];
    if(itemWt<=w){
        int item1=knapsack(val,wt,w-itemWt,n-1,dp)+itemVal;
        int item2=knapsack(val,wt,w,n-1,dp);
        dp[n][w]=max(item1,item2);
    }
    else{
        dp[n][w]=knapsack(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}
int main(){
     vector<int>val={15, 14, 10, 45, 30};
    vector<int>wt={ 2,  5,  1,  3,  4};
    int w=7;
    int n=5;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<knapsack(val,wt,w,n,dp);
}