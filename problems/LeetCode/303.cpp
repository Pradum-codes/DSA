#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        vector<int>p_sum(nums.size());
        p_sum[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            p_sum[i] = p_sum[i-1] + nums[i];
        }
        arr = p_sum;
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return arr[right];
        return arr[right] - arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0,2);
    cout << param_1 << endl;

}
