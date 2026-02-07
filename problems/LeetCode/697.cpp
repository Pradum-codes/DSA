#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first_pos;
        unordered_map<int, int> last_pos;

        for(int i = 0; i < nums.size(); i++){
            if(freq[nums[i]] == 0) {
                first_pos[nums[i]] = i;
            }
            freq[nums[i]]++;
            last_pos[nums[i]] = i;
        }

        int max_freq = 0;
        for(auto& p : freq) {
            max_freq = max(max_freq, p.second);
        }

        int min_length = nums.size();
        for(auto& p : freq) {
            if(p.second == max_freq) {
                int length = last_pos[p.first] - first_pos[p.first] + 1;
                min_length = min(min_length, length);
            }
        }

        return min_length;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];
       
    Solution sol;
    cout << sol.findShortestSubArray(nums) << endl;
    return 0;
}
