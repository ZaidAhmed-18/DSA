## Intuition

For any position, the amount of water it can trap depends on the smaller of the maximum heights on its left and right.

Instead of explicitly finding the left maximum and right maximum for every index, we use two pointers:

- `left` starts from the beginning.
- `right` starts from the end.
- `leftMax` stores the maximum height encountered from the left.
- `rightMax` stores the maximum height encountered from the right.

The key observation is:

If `height[left] < height[right]`, then the left side is the limiting side.

This means the water trapped at `left` can be determined using only `leftMax`, because there is guaranteed to be a bar on the right that is at least as tall as `height[left]`.

Similarly, if `height[right] <= height[left]`, the right side is the limiting side, so we can determine the trapped water at `right` using `rightMax`.

Therefore, we only need to process one pointer at a time and move it toward the center.

## Approach

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`

2. Maintain:
   - `leftMax` = maximum height encountered from the left.
   - `rightMax` = maximum height encountered from the right.

3. While `left < right`:
   - If `height[left] < height[right]`:
     - The left side is the limiting boundary.
     - If `height[left] < leftMax`, water can be trapped:
       `leftMax - height[left]`
     - Otherwise update `leftMax`.
     - Move `left` forward.
   - Otherwise:
     - The right side is the limiting boundary.
     - If `height[right] < rightMax`, water can be trapped:
       `rightMax - height[right]`
     - Otherwise update `rightMax`.
     - Move `right` backward.

4. Add the trapped water at each processed position to `totalVol`.

5. Return `totalVol`.

## Time Complexity

Each pointer moves from one end toward the other, and every index is processed at most once.

**Time Complexity: `O(n)`**

## Space Complexity

Only a few variables are used regardless of the input size.

**Space Complexity: `O(1)`**
