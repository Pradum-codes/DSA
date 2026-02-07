#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//OPTIMIZED
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> &last = result.back();

            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         for (int i = 0; i < n - 1; ++i) {
//             int min_idx = i;
//             for (int j = i + 1; j < n; ++j) {
//                 if (intervals[j][0] < intervals[min_idx][0]) {
//                     min_idx = j;
//                 }
//             }
//             swap(intervals[i], intervals[min_idx]);
//         }

//         vector<vector<int>> result;
//         result.push_back(intervals[0]);
        
//         for (int i = 1; i < n; ++i) {
//             vector<int> &last = result.back();
//             if (last[1] >= intervals[i][0]) {
//                 last[1] = max(last[1], intervals[i][1]);
//             } else {
//                 result.push_back(intervals[i]);
//             }
//         }

//         return result;
//     }
// };

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    Solution sol;
    intervals = sol.merge(intervals);
    
    cout << endl;
    for(int i = 0; i<intervals.size(); i++){
        for (int j = 0; j < 2; j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }
}