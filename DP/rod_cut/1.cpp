#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rod_cut(vector<int>price,vector<int>length,int rodLength){
int n=length.size();
vector<vector<int>>dp(n+1,vector<int>(rodLength+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=rodLength;j++){
        if(length[i-1]<=j){
            dp[i][j]=max(dp[i-1][j],dp[i][j-length[i-1]]+price[i-1]);
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
    }
}
return dp[n][rodLength];
}



int main(){
    vector<int>price={1,5,8,9,10,17,17,20};
    vector<int>lentgh={1,2,3,4,5,6,7,8};
    int rodLength=8;
}