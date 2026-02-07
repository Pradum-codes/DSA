#include <bits/stdc++.h>
#include "../utils/ll.h"

using namespace std;

class Solution {
public:
// OPTIMAL
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
                ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }

    // ListNode* oddEvenList(ListNode* head) {
    //     if (!head) return nullptr;  // handle empty list

    //     ListNode* temp = head;
    //     ListNode* newHead = nullptr;
    //     ListNode* newTemp = nullptr;

    //     while (temp != nullptr) {
    //         ListNode* newNode = new ListNode(temp->val);
    //         if (newTemp == nullptr) {
    //             newHead = newNode;
    //             newTemp = newHead;
    //         } else {
    //             newTemp->next = newNode;
    //             newTemp = newTemp->next;
    //         }

    //         // jump 2 steps safely
    //         if (temp->next != nullptr)
    //             temp = temp->next->next;
    //         else
    //             break;
    //     }

    //     temp = head->next;
    //     while (temp != nullptr) {
    //         ListNode* newNode = new ListNode(temp->val);
    //         newTemp->next = newNode;
    //         newTemp = newTemp->next;

    //         if (temp->next != nullptr)
    //             temp = temp->next->next;
    //         else
    //             break;
    //     }

    //     return newHead;
    // }
};


/*
1 2 3 4 5

1 3 5 2 4
*/

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
    head =  sol.oddEvenList(head);
    printLL(head);
    return 0;
}