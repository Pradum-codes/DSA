# 📘 Linked List Theory

A **Linked List** is a linear data structure where elements (called **nodes**) are connected using **pointers**.  
Unlike arrays, elements in a linked list are not stored in contiguous memory locations.  

---

## 🔑 Why Linked Lists?

- **Dynamic Size**: Unlike arrays, size can grow/shrink at runtime.
- **Efficient Insert/Delete**: O(1) if position known (no shifting like arrays).
- **Better Memory Utilization**: Useful when memory fragmentation occurs.

⚠️ But:
- **Random Access is O(n)**
- Requires **extra memory** for pointers.

---

## 📍 Structure of a Node

```cpp
struct ListNode {
    int val;             // data
    ListNode* next;      // pointer to next node
};
```

## Visual Representation
```bash
A[Data: 10 | Next] --> B[Data: 20 | Next] --> C[Data: 30 | Next] --> D[NULL]
```

## Types of Linked Lists
### 1️⃣ Singly Linked List
Each node points to the next.
Last node points to NULL.
```bash
A[10] --> B[20] --> C[30] --> D[NULL]
```
### 2️⃣ Doubly Linked List
Each node has prev and next pointers.
Allows traversal in both directions.

```bash
NULL <--> A[10] <--> B[20] <--> C[30] <--> NULL
```

### 3️⃣ Circular Linked List
Last node points back to the head, forming a circle.
```bash
A[10] --> B[20] --> C[30] --> A
```

## ⚙️ Core Operations
| Operation        | Singly | Doubly |
| ---------------- | ------ | ------ |
| Insert at Head   | O(1)   | O(1)   |
| Insert at Tail   | O(n)   | O(1)   |
| Deletion at Head | O(1)   | O(1)   |
| Deletion at Tail | O(n)   | O(1)   |
| Search           | O(n)   | O(n)   |


✍️ Example: Insertion at Head (Singly)
```bash
ListNode* insertAtHead(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    return newNode;
}
```
```Visualization
 NewNode[New Node: 5] --> OldHead[10] --> B[20] --> C[30] --> NULL
```

### 🔄 Example: Reverse a Linked List
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
```
```bash
A[10] --> B[20] --> C[30] --> D[40] --> NULL
```

## ➡️ After reversal:
```bash
D[40] --> C[30] --> B[20] --> A[10] --> NULL
```