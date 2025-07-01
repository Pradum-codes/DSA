#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int window_size = 1;
            int max = 0;
            // 1 1 0 1 1 1
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] == 1){
                    window_size++;
                } else {
                    max = window_size;
                    window_size = 0;
                }
            }
    
            return max;
        }
    };

int main(){
    int n;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i<n; i++){
        int num;
        cin >> num;

        arr.push_back(num);
    }
    
    Solution obj;
    int sol = obj.findMaxConsecutiveOnes(arr);
    cout << sol;
}