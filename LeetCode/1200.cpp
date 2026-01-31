#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        int min_diff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i + 1] - arr[i];

            if (diff < min_diff) {
                min_diff = diff;
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
            } 
            else if (diff == min_diff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i =0 ; i<n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    vector<vector<int>> res =  sol.minimumAbsDifference(arr);

    for(int i =0; i<res.size(); i++) {
        cout << "[";
        for(int j = 0; j<res[0].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]";
    }
    return 0;
}