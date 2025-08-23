#include <bits/stdc++.h>
#include "../utils/ll.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int count = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            count++;
        }

        tail->next = head;

        k = k % count;  
        int stepsToNewHead = count - k;

        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
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