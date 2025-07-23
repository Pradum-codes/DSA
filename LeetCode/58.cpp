class Solution {
    public:
        int lengthOfLastWord(string s) {
            int i = s.size()-1;
            int j;
            if(s[i] == ' '){
                while(s[i] == ' '){
                    i--;
                }
            }
            int count = 0;
            while(s[i] != ' '){
                count++;
                i--;
            }
    
            return count;
        }
    };