#include <iostream>
using namespace std;

class Solution {
    public:
        bool canPartition(string numStr, int index, int targetSum, int currentSum) {
            if (index == numStr.size()) {
                return currentSum == targetSum;
            }
    
            int num = 0;
            for (int i = index; i < numStr.size(); i++) {
                num = num * 10 + (numStr[i] - '0'); 
                cout << num << endl;
                if (canPartition(numStr, i + 1, targetSum, currentSum + num)) {
                    return true;
                }
            }
            return false;
        }
    
        bool isValid(int n) {
            int square = n * n;
            string squareStr = to_string(square);
            return canPartition(squareStr, 0, n, 0);
        }
    
        int punishmentNumber(int n) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                if (isValid(i)) {
                    sum += i * i;
                }
            }
            return sum;
        }
    };
    
int main(){
    Solution sol;
    int n;
    cin >> n;
    int solut = sol.punishmentNumber(n);
    cout << solut;
}

//  ///https://leetcode.com/problems/find-the-punishment-number-of-an-integer/?envType=daily-question&envId=2025-02-15