#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int m1 = 100; 
        int m2 = 100;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < m1){
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] < m2){
                m2 = nums[i];
            }
        }
        return nums[0] + m1 + m2;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.minimumCost(nums) << endl;
    return 0;
}
