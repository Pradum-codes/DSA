#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        return 0;   
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; cin >> m >> n;
    vector<vector<int>> matrix;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++){
            int ele;
            cin >> ele;
            matrix[i].push_back(ele);
        }
    }
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    Solution sol;
    sol.countSquares(matrix);
    return 0;
}