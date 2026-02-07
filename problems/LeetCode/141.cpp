#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertAtTail(ListNode* head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) return newNode;
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        return head;
    }
    
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head = nullptr;

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele; 
        cin >> ele;
        head = sol.insertAtTail(head, ele);
    }

    ListNode* res = nullptr;
    if(sol.hasCycle(head)){
        cout << "The List has Loop";
    } else {
        cout << "The List does not has Loop";
    }
    
    cout << "NULL\n";

    return 0;
}
