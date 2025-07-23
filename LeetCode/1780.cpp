#include <iostream>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            bool check = true;
            while(n != 0){
                int rem = n%3;
                n /= 3;
                if(rem == 2){
                    check = false;
                    break;
                }
            }
    
            return check;
        }
    };

int main(){
    int n;
    cin >> n;

    Solution sol;
    bool result = sol.checkPowersOfThree(n);
    if(result){
        cout << true;
    } else {
        cout << false;
    }
}