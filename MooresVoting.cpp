#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            } else if(nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == ele) cnt1++;
        }

        if(cnt1 > (nums.size()/2)){
            return ele;
        }

        return -1;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.majorityElement(nums);
}
