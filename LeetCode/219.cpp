#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1 || k == 0) return false;
        
        unordered_map<int,int> mp;

        int windowSize = min(k, (int)nums.size() - 1);
        for(int i = 0; i <= windowSize; i++){
            if(mp.find(nums[i]) != mp.end()) return true;
            mp[nums[i]]++;
        }

        for(int i = windowSize + 1; i < nums.size(); i++){
            mp[nums[i - k - 1]]--;
            if(mp[nums[i - k - 1]] == 0) {
                mp.erase(nums[i - k - 1]);
            }
            
            if(mp.find(nums[i]) != mp.end()) return true;
    
            mp[nums[i]]++;
        }
        
        return false;
    }
};

int main() {
    int n,k; cin >> n >> k;
    vector<int> nums(n);

    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    if(sol.containsNearbyDuplicate(nums, k)) cout <<"T"<<endl;
    else cout << "F" << endl;
}
