#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords;
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelErrorMap;

        // Helper lambda to lowercase a word
        auto toLower = [](const string& word) {
            string res = word;
            transform(res.begin(), res.end(), res.begin(), ::tolower);
            return res;
        };

        // Helper lambda to mask vowels in a word
        auto maskVowels = [](const string& word) {
            string res = word;
            for (char& ch : res) {
                ch = tolower(ch);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    ch = '*';
                }
            }
            return res;
        };

        // Preprocessing wordlist
        for (const string& word : wordlist) {
            exactWords.insert(word);

            string wordLower = toLower(word);
            if (caseInsensitiveMap.find(wordLower) == caseInsensitiveMap.end()) {
                caseInsensitiveMap[wordLower] = word;
            }

            string vowelMasked = maskVowels(word);
            if (vowelErrorMap.find(vowelMasked) == vowelErrorMap.end()) {
                vowelErrorMap[vowelMasked] = word;
            }
        }

        vector<string> result;

        for (const string& query : queries) {
            if (exactWords.count(query)) {
                result.push_back(query);
                continue;
            }

            string queryLower = toLower(query);
            if (caseInsensitiveMap.count(queryLower)) {
                result.push_back(caseInsensitiveMap[queryLower]);
                continue;
            }

            string queryMasked = maskVowels(query);
            if (vowelErrorMap.count(queryMasked)) {
                result.push_back(vowelErrorMap[queryMasked]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<string> words(n), queries(n);

    for(int i = 0; i<n; i++) cin >> words[i];
    for(int i = 0; i<n; i++) cin >> queries[i];

    Solution sol;
    vector<string> res = sol.spellchecker(words, queries);

    return 0;
}