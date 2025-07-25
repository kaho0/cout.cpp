#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(vector<int>val,vector<int>wt,int w,int n,vector<vector<int>>&dp){
    if(n==0||w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    } 
    int itemW=wt[n-1];
    int itemVal=val[n-1];
    if(itemW<=w){  //if the item weight is less than or equal to the remaining weight
        //we have two choices: either take the item or skip it
        int ans1=knapsack(val,wt,w-itemW,n-1,dp)+itemVal; //take the weight
        int ans2=knapsack(val,wt,w,n-1,dp);//skip weight
        dp[n][w]=max(ans1,ans2);
    }
    else{
        // we CAN'T take the item → only choice is to skip it
        dp[n][w]=knapsack(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}
int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int w=7;
    int n=5;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<knapsack(val,wt,w,n,dp)<<endl;
    cout<<"memo matrix:"<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}

//val-value array
//wt-weight array
//w-remaining weight
//n-number of items
//dp-memoization matrix