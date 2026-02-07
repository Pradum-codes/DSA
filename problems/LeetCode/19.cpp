#include <bits/stdc++.h>
#include "../utils/ll.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        head = dummy->next;
        delete dummy;
        return head;
    }


    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (!head) return nullptr;

    //     int count = 0;
    //     ListNode* temp = head;
    //     while (temp != nullptr) {
    //         count++;
    //         temp = temp->next;
    //     }

    //     if (n == count) {
    //         ListNode* nodeToDelete = head;
    //         head = head->next;
    //         delete nodeToDelete;
    //         return head;
    //     }

    //     temp = head;
    //     for (int i = 0; i < count - n - 1; i++) {
    //         temp = temp->next;
    //     }

    //     ListNode* nodeToDelete = temp->next;
    //     temp->next = temp->next->next;
    //     delete nodeToDelete;

    //     return head;
    // }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ListNode* head = nullptr;    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    
    Solution sol;
    head = createLL(arr);
    head =  sol.removeNthFromEnd(head, k);
    printLL(head);
    return 0;
}