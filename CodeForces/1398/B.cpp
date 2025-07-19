#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int count = 0;
        vector<int> ones_blocks;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '1') {
                count++;
            } else {
                if(count != 0) {
                    ones_blocks.push_back(count);
                    count = 0;
                }
            }
        }

        if(count != 0) {
            ones_blocks.push_back(count);
        }

        sort(ones_blocks.begin(), ones_blocks.end(), greater<int>());

        int score = 0;
        for(int i = 0; i < ones_blocks.size(); i += 2) {
            score += ones_blocks[i];
        }

        cout << score << endl;
    }

    return 0;
}
