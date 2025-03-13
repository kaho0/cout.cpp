#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool isAnagram(string s,string t){
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>charCount;
        for(char c:s)charCount[c]++;
        for(char c:t){
   if(charCount[c]==0)return false;
            charCount[c]--;    }
       return true;
    }
};
int main(){
    Solution solution;
    cout<<solution.isAnagram("listen","silent")<<endl;
    cout<<solution.isAnagram("cat","rat")<<endl;
}