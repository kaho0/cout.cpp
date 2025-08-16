#include<iostream>
#include<vector>
using namespace std;
int diagonalSum(vector<vector<int>>&matrix){
    int n=matrix.size();
    int sum=0;
        for(int i=0;i<n;i++){
        sum+=matrix[i][i];
        sum+=matrix[i][n-i-1];
        }
        if(n%2==1){
            sum-=matrix[n/2][n/2];
        }
        return sum;
    }
int main(){
    int n;
     cout << "Enter size of square matrix: ";
    cin >> n;
    vector<vector<int>>matrix(n,vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << " Entered matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = diagonalSum(matrix);
    cout << "\nSum of diagonals: " << sum << endl;

    return 0;
}
