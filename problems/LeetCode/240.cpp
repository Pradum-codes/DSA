#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;

        while(row<m && col>=0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col++;
        }

        return false;    
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         bool found = false;
//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[i].size(); j++){
//                 if(matrix[i][j] == target) {
//                     found = true;
//                     break;
//                 }
//             }
//             if(found) break;
//         }

//         return found;    
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    Solution sol;
    if(sol.searchMatrix(matrix, target)) cout << "Target Found" << endl;
    else cout << "Target NOT found" << endl;

    return 0;
}
