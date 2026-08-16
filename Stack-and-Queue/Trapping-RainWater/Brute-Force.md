## Intuition

Water can be trapped at an index only when there is a boundary on both sides.

For every index `i`, I first find the Next Greater or Equal Element (NGE) on its right using a monotonic stack.

- If an NGE exists, it can act as the right boundary.
- If no NGE exists, I use the maximum-height element in the remaining suffix as a possible right boundary.
- `SuffixMaxIdx[i]` stores the index of the maximum element from `i` to the end.

Once both boundaries are known:

water level = min(left boundary height, right boundary height)

The total possible volume between the two boundaries is:

width × water level

Then I subtract the heights of all bars between them to get the trapped water.

After processing a region, I skip directly to the right boundary instead of processing every index again.

## Approach

1. Build the `NGE` array using a monotonic stack.
   - `nge[i]` stores the index of the first element to the right whose height is greater than or equal to `height[i]`.

2. Build the `SuffixMaxIdx` array.
   - `SuffixMaxIdx[i]` stores the index of the maximum-height element from `i` to `n - 1`.

3. Iterate through the array from left to right.

4. For each index:
   - If an NGE exists, use it as the right boundary.
   - Otherwise, use the maximum element in the remaining suffix as the right boundary.

5. Calculate the water level:
   `min(height[left], height[right])`

6. Calculate the maximum possible volume between the boundaries:
   `(right - left - 1) × water level`

7. Subtract the heights of all bars between the two boundaries.

8. Move directly to the right boundary and continue processing.

## Time Complexity

- NGE: `O(n)` because every element is pushed and popped from the stack at most once.
- Suffix Maximum: `O(n)`.
- Main traversal: `O(n)` because after processing a region, the index jumps to the right boundary.

Overall Time Complexity: `O(n)`

## Space Complexity

- NGE array: `O(n)`
- Suffix maximum index array: `O(n)`
- Monotonic stack: `O(n)`

Overall Space Complexity: `O(n)`
