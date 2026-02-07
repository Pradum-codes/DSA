#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        int row = 0, col = 0;
        bool up = true;
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (up) {
                if (col == n - 1) {
                    row++;
                    up = false;
                } else if (row == 0) {
                    col++;
                    up = false;
                } else {
                    row--;kw
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    up = true;
                } else if (col == 0) {
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; cin >> m >> n;
    vector<vector<int>> matrix;
    for(int i = 0; i<n; i++) {
        int ele; 
        vector<int> row;    
        for(int j = 0; j<n; j++){
            cin >> ele;
            row.push_back(ele);
        }
        matrix.push_back(row);
    }
        
    Solution sol;
    vector<int> result = sol.findDiagonalOrder(matrix);

    for(int i = 0; i<result.size(); i++) cout << result[i] << " ";

    return 0;
}