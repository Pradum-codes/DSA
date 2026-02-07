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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (list1 && list2) {
            ListNode* newNode;
            if (list1->val < list2->val) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (!head) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        while (list1) {
            ListNode* newNode = new ListNode(list1->val);
            tail ? tail->next = newNode : head = newNode;
            tail = newNode;
            list1 = list1->next;
        }

        while (list2) {
            ListNode* newNode = new ListNode(list2->val);
            tail ? tail->next = newNode : head = newNode;
            tail = newNode;
            list2 = list2->next;
        }

        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele; 
        cin >> ele;
        head1 = sol.insertAtTail(head1, ele);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele; 
        cin >> ele;
        head2 = sol.insertAtTail(head2, ele);
    }

    ListNode* res = nullptr;
    ListNode* temp = sol.mergeTwoLists(head1,head2);
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
