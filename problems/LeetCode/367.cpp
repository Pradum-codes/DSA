#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long h = num;

        while(l<=h){
            long mid = l-(l-h)/2;
            long val = mid*mid;
            if(val == num) return true;
            else if(val < num) l = mid+1;
            else h = mid-1;
        }

        return false;
    }
};

int main() {
    int n; cin>>n;

    Solution sol;
    if(sol.isPerfectSquare(n)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;
}
