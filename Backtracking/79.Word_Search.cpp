#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool search(vector<vector<char>>&board,vector<vector<bool>>&visited,int i,int j,int idx,const string &word){
        if(idx==word.length())return true;
        int m=board.size(),n=board[0].size();
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||board[i][j]!=word[idx])return false;
        visited[i][j]=true;
        for(auto &dir:directions){
            int new_i=i+dir[0],new_j=j+dir[1];
            if(search(board,visited,new_i,new_j,idx+1,word))return true;
        }
             visited[i][j]=false;
        return false;
            
    }
    bool exists(vector<vector<char>>&board,string word){
           int m=board.size(),n=board[0].size();
           vector<vector<bool>>visited(m,vector<bool>(n,false));
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]&&search(board,visited,i,j,0,word))
                return true;
            }
           }
           return false;

    }
};

int main(){
    Solution sol;
     vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
                                  string word = "ABCCED";
                            cout<<(sol.exists(board,word)?"True":"False")<<endl;
 word = "SEE";
    cout << (sol.exists(board, word) ? "True" : "False") << endl;
}