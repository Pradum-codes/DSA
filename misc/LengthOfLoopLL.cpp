#include <bits/stdc++.h>
#include "../utils/ll.h"
using namespace std;

class Solution {
public:
    int LengthOfLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int l = 1;
                ListNode* it = slow->next;
                while (it != slow) {
                    l++;
                    it = it->next;
                }
                return l;
            }
        }
        return 0;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head = nullptr;

    int n; 
    cin >> n;
    vector<int> list(n);
    for(int i = 0; i<n; i++) cin >> list[i];
    head = createLL(list);
    createLoop(head, 2);
    cout << "Length Of Loop" << sol.LengthOfLoop(head) << endl;
    printLL(head);

    return 0;
}
