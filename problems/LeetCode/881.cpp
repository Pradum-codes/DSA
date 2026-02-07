#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int count = 0;
        int l = 0, r =n-1;

        while(l<=r){
            if(people[l]+people[r] > limit){
                count++;
                r--;
            }else if(people[l]+people[r] <= limit){
                count++;
                l++;
                r--;
            }
        }

        return count;
    }
};

int main() {
    int n, limit; cin >> n >> limit;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) cin >> nums[i];

    Solution sol;

    cout << sol.numRescueBoats(nums, limit) << endl;

    return 0;
}
