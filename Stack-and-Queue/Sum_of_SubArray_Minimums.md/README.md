## Intuition

Instead of generating every subarray and finding its minimum, we consider each element as the minimum and determine how many subarrays it contributes to.

For every `nums[i]`, we find:

- **Previous Smaller Element (PSE)** → the closest smaller element on the left.
- **Next Smaller Element (NSE)** → the closest smaller element on the right.

If:

- `left = i - pse[i]`
- `right = nse[i] - i`

then `nums[i]` is the minimum of `left × right` subarrays.

Therefore, its contribution is:

`nums[i] × left × right`

The answer is the sum of the contributions of all elements.

## Approach

1. Use a monotonic increasing stack to find the Next Smaller Element (NSE) for every index.
2. Clear the stack and use it again to find the Previous Smaller Element (PSE).
3. While finding NSE, remove elements `>= nums[i]`.
4. While finding PSE, remove elements `> nums[i]`.
5. The asymmetric comparisons handle duplicate elements and ensure that each subarray is counted exactly once.
6. For every index `i`:
   - Calculate the number of possible starting positions using `i - pse[i]`.
   - Calculate the number of possible ending positions using `nse[i] - i`.
   - Add `nums[i] × left × right` to the answer.
7. Return the result modulo `10^9 + 7`.

## Time Complexity

`O(n)`

Each element is pushed and popped from the monotonic stack at most once in each pass.

## Space Complexity

`O(n)`

The PSE array, NSE array, and monotonic stack require linear extra space.
