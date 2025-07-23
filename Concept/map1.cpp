#include <iostream>
#include <map>

using namespace std;

void countOccur(map<char,int>& dict, string str){
    for(char c : str){
        dict[c] += 1;
    }
}

char mostFrequent(map<char, int>& dict){
    int max = 0;
    char maxFreq;

    for(auto ch : dict){
        if(ch.second > max){
            max = ch.second;
            maxFreq = ch.first;
        }
    }

    return maxFreq;
}

int main() {
    map<char,int> dict;
    string str;
    cin >> str;
    countOccur(dict, str);

    for(auto ch : dict){
        cout << ch.first << " " << ch.second << endl;
    }

    cout << "Character with most frequency: " << mostFrequent(dict);

    return 0;
}