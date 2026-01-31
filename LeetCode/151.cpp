#include <iostream>
#include <vector>

using namespace std;

// Brute Force
class Solution {
public:
    string reverseWord(string s) {
        vector<string> words;
        int n = s.length();
        int j = 0;
        for(int i = 0; i<n;i++){
            if(s[i] == ' '){
                words.push_back(s.substr(j, j-i));
            }else{
                j=i;
            }
        }
        string ans = "";
        for(int i = words.size()-1; i>=0; i--){
            ans+= words[i];
        }

        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.reverseWord(s) << endl;
}