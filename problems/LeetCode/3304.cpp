#include <iostream>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string org = "a";
        while(org.size() <= k){
            int i = 0;
            string temp = "";
            while (i<org.size())
            {
                temp += (org[i] + 1);
                i++;
            }
            org.append(temp);
        }
        return org[k- 1];
    }
};

int main() {
    Solution sol;
    int k;
    cin >> k;
    cout << sol.kthCharacter(k) << endl;
}