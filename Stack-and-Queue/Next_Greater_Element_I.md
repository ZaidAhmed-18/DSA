# Next Greater Element I

## Intuition

For every element in `nums2`, we need to find the **first element to its
right that is greater than it**.

A brute-force approach would scan to the right for every element, which
can take `O(m²)`.

Instead, we use a **monotonic decreasing stack**.

The key observation is:

> While processing `nums2` from **right to left**, elements that are
> smaller than or equal to the current element can never be the next
> greater element for the current element or any element further to its
> left.

So, we remove them from the stack.

After removing all invalid candidates:

-   If the stack is empty → there is no greater element → `-1`
-   Otherwise → `st.top()` is the next greater element

We store each answer in a hash map:

``` text
element → next greater element
```

Then we can directly construct the answer for `nums1`.

------------------------------------------------------------------------

## Approach

1.  Traverse `nums2` from **right to left**.
2.  Maintain a stack of possible next-greater candidates.
3.  For the current element:
    -   Pop all elements `<= current`.
    -   The remaining top, if any, is its next greater element.
    -   Store the result in `unordered_map`.
    -   Push the current element onto the stack.
4.  Traverse `nums1` and retrieve each element's answer from the map.

### Why can we pop elements?

Suppose we're processing `4` and the stack contains `3`.

``` text
... 4 ... 3
        ↑
     candidate
```

`3` can be discarded because `4` is:

-   greater than `3`
-   closer to every element on its left

Therefore, `3` can never be the **next** greater element for anything we
process later.

This is the core idea behind the monotonic stack.

------------------------------------------------------------------------

## Complexity

Let:

-   `n = nums1.size()`
-   `m = nums2.size()`

### Time Complexity

The stack processing is **O(m) amortized**:

-   Every element is pushed once.
-   Every element is popped at most once.

Building the result from `nums1` takes average `O(n)` due to
`unordered_map` lookups.

**Time Complexity: `O(m + n)`**

### Space Complexity

-   Stack: `O(m)`
-   Hash map: `O(m)`
-   Result: `O(n)`

Including the output:

**Space Complexity: `O(m + n)`**

Auxiliary space excluding the result:

**`O(m)`**

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;

        stack<int> st;

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Remove elements that cannot be the next greater element
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            // Top is the next greater element
            nge[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> result;

        // Get answers for nums1 using the precomputed map
        for (int x : nums1)
            result.push_back(nge[x]);

        return result;
    }
};
```

------------------------------------------------------------------------

## Pattern to Remember

**Next Greater Element → Monotonic Stack → Process from right to left**

The important part is not memorizing the code. Remember the reasoning:

> **Remove candidates that are smaller/equal because a better and closer
> candidate has already made them useless.**
