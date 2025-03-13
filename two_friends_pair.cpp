#include<iostream>
#include<string>
using namespace std;
int frind_pair(int n){
if(n==1||n==2){
    return n;
}

    return frind_pair(n-1)+(n-1)*frind_pair(n-2);
}
int main(){
    cout<<frind_pair(3)<<endl;
}