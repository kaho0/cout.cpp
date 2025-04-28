#include<iostream>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR=0;
        for(char &ch:s){
            XOR^=ch;
        }
        for(char&ch:t){
            XOR^=ch;
        }
        return(char)XOR;
        
    }
};
int main(){
   Solution sol;
   string s="abcd";
   string t="abcde";
   char result=sol.findTheDifference(s,t);
   cout << "The extra character is: " << result << endl;

}