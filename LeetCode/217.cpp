#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                return true;
            }
            map[nums[i]] = 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }

    bool result = sol.containsDuplicate(arr);
    cout << result << endl;
    
    return 0;
}