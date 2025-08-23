#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;  // total number of subsets = 2^n
        vector<vector<int>> result;

        for(int mask = 0; mask < subsets; mask++) {
            vector<int> sub;
            for(int i = 0; i < n; i++) {   // FIXED: include last element
                if(mask & (1 << i)) 
                    sub.push_back(nums[i]);
            }
            result.push_back(sub);
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    Solution sol;
    vector<vector<int>> result = sol.subsets(arr);
    
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}
