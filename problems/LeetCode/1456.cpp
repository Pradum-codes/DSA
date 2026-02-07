#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isVowel(char c){
        string s = "aeiou";
        if(s.find(c) != string::npos){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int j = s.length()-1;
        int v_count = 0;
        for(int i = 0; i<k; i++){
            if(isVowel(s[i])) v_count++;
        }
        int max_count = v_count;

        for(int i = k; i<s.length(); i++){
            if(isVowel(s[i])){
                v_count++;
            }
            if(isVowel(s[i-k])){
                v_count--;
            }

            max_count = max(max_count, v_count);
        }

        return max_count;
    }
};

int main() {
    string s;
    int k; 
    cin >> s >> k;
    
    Solution sol;
    cout << sol.maxVowels(s,k) << endl;
}
