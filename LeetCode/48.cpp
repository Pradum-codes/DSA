#include <iostream>
#include <vector>

using namespace std;

// OPTIMIZED
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> result(n, vector<int>(n));
        
//         for(int i = 0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 result[j][m - i - 1] = matrix[i][j];
//             }
//         }

//         for(int i = 0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 matrix[i][j] = result[i][j];
//             }
//         }
//     }
// };


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    sol.rotate(matrix);

    cout << "Modified matrix:" << endl;
    printMatrix(matrix);

    return 0;
}