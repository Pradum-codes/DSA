#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> set;
    int ele;
    for(int i = 0; i<4; i++){
        cin >> ele;
        set.insert(ele);
    }
    int result = 4 - set.size();
    cout << result << endl;

    return 0;
}