#include <iostream>
#include <vector>
using namespace std;

// OPTIMIZED
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int b = 0, s = 0;
//         int n = prices.size();
//         int profit = 0;
//         for(int i = 0; i<n-1; i++){
//             for(int j = i+1; j<n; j++){
//                 int p = prices[j] - prices[i];
//                 profit = max(p,profit);
//             }
//         }

//         return profit;
//     }
// };

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i<n; i++){
        cin >> prices[i];
    }
    Solution sol;
    cout << sol.maxProfit(prices) << endl;

}