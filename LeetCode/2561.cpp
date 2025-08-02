#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> count;
        int n = basket1.size();
        
        // Count frequency of each fruit
        for(int x: basket1) count[x]++;
        for(int x: basket2) count[x]++;
        
        // Check feasibility
        for(auto [fruit, freq] : count) {
            if(freq % 2 != 0) return -1;
        }
        
        unordered_map<int,int> freq1, freq2;
        for(int x: basket1) freq1[x]++;
        for(int x: basket2) freq2[x]++;
        
        int minFruit = INT_MAX;
        for(auto [fruit, _] : count) {
            minFruit = min(minFruit, fruit);
        }
        
        vector<int> extra1, extra2;
        for(auto [fruit, freq] : count) {
            int half = freq / 2;
            if(freq1[fruit] > half) {
                for(int i=0; i<freq1[fruit]-half; i++)
                    extra1.push_back(fruit);
            }
            else if(freq2[fruit] > half) {
                for(int i=0; i<freq2[fruit]-half; i++)
                    extra2.push_back(fruit);
            }
        }
        
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());
        
        long long cost = 0;
        for(int i=0; i<extra1.size(); i++) {
            int a = extra1[i];
            int b = extra2[i];
            cost += min((long long)min(a, b), (long long)2 * minFruit);
        }
        return cost;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    
    vector<int> b1(n), b2(n);
    for(int i = 0; i<n; i++) cin >> b1[i];
    for(int i = 0; i<n; i++) cin >> b2[i];

    Solution sol;
    cout << sol.minCost(b1,b2);
    return 0;
}