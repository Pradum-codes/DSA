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
    
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }

        if (!cycle) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*> visited;

    //     ListNode* temp = head;
    //     while (temp != nullptr) {
    //         if (visited.find(temp) != visited.end()) {
    //             return temp;
    //         }
    //         visited.insert(temp);
    //         temp = temp->next;
    //     }
    //     return nullptr;
    // }

};