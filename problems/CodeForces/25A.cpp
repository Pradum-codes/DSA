#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> oddIndexes, evenIndexes;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 0)
            evenIndexes.push_back(i + 1);
        else
            oddIndexes.push_back(i + 1);
    }

    if (oddIndexes.size() == 1)
        cout << oddIndexes[0] << endl;
    else
        cout << evenIndexes[0] << endl;

    return 0;
}
