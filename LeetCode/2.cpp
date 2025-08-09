#include <bits/stdc++.h>
#include "../utils/ll.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy.next;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;

    vector<int> num1(n);
    vector<int> num2(m);
    for(int i = 0; i<n; i++) cin >> num1[i];
    for(int i = 0; i<m; i++) cin >> num2[i];

    ListNode* n1 = createLL(num1);
    ListNode* n2 = createLL(num2);
    Solution sol;
    ListNode* res = sol.addTwoNumbers(n1,n2);
    printLL(res);
    
    return 0;
}