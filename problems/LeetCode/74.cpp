#include <bits/stdc++.h>
using namespace std;

// OPTIMAL AND CLEAN
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

// OPTIMAL
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         int top = 0;
//         int bottom = m - 1;
//         int row = -1;
        
//         while (top <= bottom) {
//             int mid = top + (bottom - top) / 2;
//             if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
//                 row = mid;
//                 break;
//             }
//             if (target > matrix[mid][n - 1]) {
//                 top = mid + 1;
//             } else {
//                 bottom = mid - 1;
//             }
//         }

//         if (row == -1) return false;

//         int l = 0, r = n - 1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (matrix[row][mid] == target) {
//                 return true;
//             }
//             if (target > matrix[row][mid]) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }

//         return false;
//     }
// };


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
