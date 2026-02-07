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

    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
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

    int pos; 
    cin >> pos;

    ListNode* temp = head;
    for (int i = 0; temp && i < pos; i++) {
        temp = temp->next;
    }

    if (temp && temp->next) {
        sol.deleteNode(temp); 
    } else {
        cout << "Invalid position (can't delete last node)\n";
    }

    temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
