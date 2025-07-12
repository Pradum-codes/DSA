#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        string str = arr[i];
        if(str.length() > 10){
            char first = str[0];
            char last = str[str.length() - 1];
            int middleCount = str.length() - 2;
            
            string result = first + to_string(middleCount) + last;
            cout << result << endl;
        } else {
            cout << str << endl;
        }
    }
}