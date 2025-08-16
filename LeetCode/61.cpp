#include <bits/stdc++.h>
#include "utils/ll.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i<k; i++) {
            
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];

    ListNode* head = createLL(arr);
    Solution sol;

    head = sol.rotateRight(head, k);
    printLL(head);

    return 0;
}