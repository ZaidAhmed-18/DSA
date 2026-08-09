# Valid Parentheses

## Problem

Given a string containing `()`, `{}`, and `[]`, determine whether the brackets are valid.

A string is valid if:

* Every opening bracket has a corresponding closing bracket.
* Brackets are closed in the correct order.
* Every closing bracket matches the most recently opened bracket.

## Intuition

A closing bracket must match the **most recently opened bracket** that hasn't been closed yet.

This follows the **Last In, First Out (LIFO)** principle, which makes a stack the natural data structure for this problem.

## Approach

1. Store all opening brackets in an `unordered_set`.
2. Store each closing bracket and its corresponding opening bracket in an `unordered_map`.
3. Traverse the string:

   * If the character is an opening bracket, push it onto the stack.
   * If it is a closing bracket, check whether the stack is non-empty and its top matches the required opening bracket.
   * If it matches, pop the stack.
   * Otherwise, return `false`.
4. After traversing the entire string, the string is valid only if the stack is empty.

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(n)`

## Solution

```cpp
class Solution {
public:
    bool isValid(const string& str) {
        const unordered_set opens = {'[', '{', '('};

        const unordered_map<char, char> opposite = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };

        stack<char> st;

        for (char bracket : str) {
            if (opens.find(bracket) != opens.end())
                st.push(bracket);
            else {
                if (!st.empty() && opposite.find(bracket)->second == st.top())
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
```
