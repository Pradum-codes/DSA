#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        int maxFromRight = nums[n-1];
        result.push_back(maxFromRight);
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] > maxFromRight){
                result.push_back(nums[i]);
                maxFromRight = nums[i];
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Solution sol;
    vector<int> result = sol.leaders(nums);
    
    // Use result.size() instead of n
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}