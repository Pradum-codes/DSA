#include <bits/stdc++.h>
#include "../utils/ll.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};

// 1 2 3 4 5

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<int> list(n);
    for(int i = 0; i<n; i++) cin >> list[i];
    ListNode* head = createLL(list);

    Solution sol;
    head = sol.reverseKGroup(head, k);
    printLL(head);
    return 0;
}