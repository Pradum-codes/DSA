#include <iostream>
using namespace std;
class Solution {
    public:
        bool isPowerOfThree(int n) {
            int res = 1;
            if(n <=0 ) return false;
            while(res < n){
                res *= 3;
                cout << res << endl;
            }
    
            if(n == res){
                return true;
            } else {
                return false;
            }
        }
    };

int main(){
    int n;
    cin >> n;

    Solution sol;
    bool result = sol.isPowerOfThree(n);

    if(result){
        cout << true;
    } else {
        cout << false;
    }
}