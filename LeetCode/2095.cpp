#include <bits/stdc++.h>
#include "../utils/ll.h"
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            ListNode* node = head;
            head = nullptr;
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ListNode* head = nullptr;    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    
    Solution sol;
    head = createLL(arr);
    head =  sol.deleteMiddle(head);
    printLL(head);
    return 0;
}

/*
1 2 3 4 5 6 7 8
  ^ ^ ^
    ^   ^   ^
1 2 3 4 5 6 7 8 9
  ^ ^ ^ ^
    ^   ^   ^   ^
*/