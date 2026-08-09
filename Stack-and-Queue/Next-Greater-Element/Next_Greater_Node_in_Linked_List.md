# LC 1019 — Next Greater Node In Linked List

## Intuition

For every node, we need to find the **first node to its right whose value is greater**.

A monotonic stack is ideal for this, but there is one problem: a linked list can naturally be traversed only from **left to right**.

So, we temporarily **reverse the linked list**.

For example:

```text
Original:   2 → 1 → 5 → 3 → 4
Reversed:   4 → 3 → 5 → 1 → 2
```

After reversing, the nodes we have already processed correspond to the nodes that were originally **to the right** of the current node.

We can therefore use a monotonic stack to find the next greater element.

For each node:

* Remove elements from the stack that are `<= current->val`.
* If the stack is empty, there is no greater element → `0`.
* Otherwise, the top of the stack is the next greater element.
* Push the current value into the stack.

Finally, reverse the linked list again to restore its original structure.

## Approach

1. Reverse the linked list and count the number of nodes.
2. Create a result array of size `n`.
3. Traverse the reversed linked list.
4. Maintain a **monotonic decreasing stack**:

   * Pop all values `<= current->val`.
   * The remaining top is the next greater value.
   * Store it in the corresponding position of `result`.
   * Push `current->val`.
5. Reverse the linked list again to restore the original list.
6. Return the result.

## Complexity

### Time Complexity

**O(n)**

* First reversal: `O(n)`
* Monotonic stack traversal: `O(n)` amortized
* Second reversal: `O(n)`

Each element is pushed and popped from the stack at most once.

### Space Complexity

**O(n)**

* Result array: `O(n)`
* Stack: `O(n)`

The linked-list reversal itself uses `O(1)` extra space.

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* revLL(ListNode* head, int& size) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* front = current->next;
            current->next = prev;
            prev = current;
            current = front;
            size++;
        }

        return prev;
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        head = revLL(head, n);

        vector<int> result(n);

        ListNode* current = head;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= current->val)
                st.pop();

            result[i] = st.empty() ? 0 : st.top();

            st.push(current->val);
            current = current->next;
        }

        // Restore the original linked list
        n = 0;
        head = revLL(head, n);

        return result;
    }
};
```
