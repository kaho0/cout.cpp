#include<iostream>

using namespace std;
void getBinary(int n,string s){
    if(s.length()==n){
        cout<<s<<endl;
        return;
    }

getBinary(n,s+"0");
if(s.empty()|| s.back()!='1'){
    getBinary(n,s+"1");
}
}

int main() {
    int n = 3;  // Change N as needed
    getBinary(n, "");
    return 0;
}