#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0;
        long long h = n;

        while(l<=h){
            long long mid = (l+h)/2;
            long long val = mid*(mid+1)/2;;
            if(val == n) return (int)mid;
            else if(val > n) h = mid-1;
            else l = mid+1;
        }
        return (int)l-1;
    }
};


int main() {
    int n; cin>>n;

    Solution sol;
    cout << sol.arrangeCoins(n) << endl;
}
