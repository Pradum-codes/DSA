#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row, col, box
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue; // skip empty

                int boxId = (i / 3) * 3 + (j / 3);

                // check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // check col
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // check box
                if (boxes[boxId].count(c)) return false;
                boxes[boxId].insert(c);
            }
        }
        return true;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    return 0;
}