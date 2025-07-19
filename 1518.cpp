#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            result += newBottles;
            emptyBottles = newBottles + (emptyBottles % numExchange);
        }

        return result;
    }
};


int main() {
    int n,k;
    cin >> n >> k;

    Solution sol;
    cout << sol.numWaterBottles(n,k);
}