# Sliding Window Maximum

## Intuition

For every sliding window, we need to find the maximum element.

A brute-force approach would find the maximum in every window using `max_element()`, which takes **O(k)** per window and results in **O(n × k)** time in the worst case.

Instead, we use a **monotonic deque**.

The deque stores **indices** of elements that can potentially become the maximum.

The deque maintains this property:

nums[dq[0]] >= nums[dq[1]] >= nums[dq[2]] >= ...

Therefore, the index at the front of the deque always represents the maximum element of the current window.

## Why Store Indices Instead of Values?

We need to know when an element leaves the sliding window.

The deque does not contain every element because smaller elements are removed when a larger element enters. Therefore, storing only values can make it impossible to determine which occurrence has expired, especially when duplicate values exist.

By storing indices, we can directly check whether the front element has left the current window.

## Algorithm

For every new element:

1. Remove elements from the back while their value is smaller than the incoming element.
   - Such elements can never become the maximum while the new element is present.
2. Add the current index to the deque.
3. The front of the deque represents the maximum of the current window.
4. Add that maximum to the result.
5. Remove the front index if it has moved outside the current window.
6. Move the sliding window forward.

## Complexity

### Time Complexity

**O(n)**

Each index is:
- pushed into the deque exactly once
- popped from the deque at most once

Therefore, the total number of deque operations is linear.

### Space Complexity

**O(k)** auxiliary space for the deque.

The result array requires **O(n)** output space.
