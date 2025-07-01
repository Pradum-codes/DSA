#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        int i = 0;
        int j = nums.size() - 1;

        while(i <= j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }else if(sum > target){
                j--;
            }else{
                i++;
            }
        }
        
        return {};
    }
};


int main() { 
    int size;
    cin >> size;
    vector<int> nums;
    
    for(int i = 0; i < size; i++){
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }

    int target;
    cin >> target;
    
    Solution obj;
    vector<int> ans = obj.twoSum(nums, target); 

    if (!ans.empty()) {  // Check if a solution was found
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
}
