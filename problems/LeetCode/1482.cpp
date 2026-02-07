#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeFlower(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int bouquets = 0;
        int consecutive = 0;
        
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                consecutive++;
                if(consecutive == k){
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total_needed = (long long)m * k;
        if (bloomDay.size() < total_needed) return -1;
        
        int min_d = *min_element(bloomDay.begin(), bloomDay.end());
        int max_d = *max_element(bloomDay.begin(), bloomDay.end());

        int l = min_d;
        int h = max_d;
        int ans = -1;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            
            if(canMakeFlower(bloomDay, mid, m, k)){
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.minDays(nums, m, k) << endl;
    return 0;
}

/*
Problem: Minimum Number of Days to Make m Bouquets
- You have n flowers that bloom on different days
- To make a bouquet, you need k adjacent flowers that have bloomed
- Find minimum days to make m bouquets
- If impossible, return -1
*/
