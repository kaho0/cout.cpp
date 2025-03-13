#include<iostream>
#include<vector>
using namespace std;
vector<int>spiral_matrix(vector<vector<int>>&matrix ){
    vector<int>result;
    if(matrix.empty()) return result;

    int srow = 0, erow = matrix.size() - 1;
    int scol = 0, ecol = matrix[0].size() - 1;
 while(srow<=erow&&scol<=ecol){
    for(int i=scol;i<=ecol;i++){
        result.push_back(matrix[srow][i]);
    }
    for(int i=srow+1;i<=erow;i++){
        result.push_back(matrix[i][ecol]);
    }
    for(int i=ecol-1;i>=scol;i--){
        result.push_back(matrix[erow][i]);
    }
    for(int i=erow-1;i>srow;i--){
        result.push_back(matrix[i][scol]);
    }
    srow++,scol++,erow--,ecol--;
 }
 return result;

}
int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Entered matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> result = spiral_matrix(matrix);

    cout << "\nSpiral order traversal:\n";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}