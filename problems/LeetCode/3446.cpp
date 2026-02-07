#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        for (auto& [key, values] : diag) {
            if (key < 0) {
                sort(values.begin(), values.end(), greater<int>());
            } else {
                sort(values.begin(), values.end());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                ans[i][j] = diag[key].back();
                diag[key].pop_back();
            }
        }

        return ans;
    }
    }
};
