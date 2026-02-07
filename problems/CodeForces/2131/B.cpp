#include <iostream>
#include <vector>

using namespace std;

// Function to solve one test case
void solve() {
    int length;
    cin >> length; // Read the length of the array

    // Create an array to store the result
    vector<int> result(length);

    if (length == 2) {
        // Special case for length 2: [-1, 2] is optimal
        result[0] = -1;
        result[1] = 2;
    } else {
        // For length >= 3, use alternating pattern: -1, 3, -1, 3, ...
        // If length is even, last two elements are -1, 2 to optimize lexicographically
        for (int i = 0; i < length; i++) {
            if (i % 2 == 0) {
                // Even-indexed positions (0, 2, 4, ...) get -1
                result[i] = -1;
            } else {
                // Odd-indexed positions (1, 3, 5, ...) get 3
                // Except for the second-to-last position in even-length arrays
                if (length % 2 == 0 && i == length - 2) {
                    result[i] = -1; // Second-to-last for even length
                } else if (length % 2 == 0 && i == length - 1) {
                    result[i] = 2;  // Last for even length
                } else {
                    result[i] = 3;
                }
            }
        }
    }

    // Print the array with spaces between elements
    for (int i = 0; i < length; i++) {
        cout << result[i];
        if (i < length - 1) {
            cout << " ";
        }
    }
    cout << "\n"; // Newline at the end
}

int main() {
    // Optimize input/output for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}