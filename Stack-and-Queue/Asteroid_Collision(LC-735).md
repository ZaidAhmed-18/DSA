# Asteroid Collision

## Intuition

Asteroids move either right (`+`) or left (`-`).

A collision can happen only when the asteroid on the stack is moving right and the current asteroid is moving left:

    stack top →    ← current asteroid

Therefore, we only need to handle collisions when:

    st.back() > 0 && ast < 0

We use a stack to keep track of the asteroids that are still alive.

## Approach

For each asteroid:

1. If no collision is possible, push the asteroid into the stack.
2. If a collision is possible:
   - Keep removing smaller asteroids from the stack while the current asteroid is larger.
   - If the stack becomes empty, the current asteroid survives, so push it.
   - If the stack top can no longer collide with the current asteroid, push the current asteroid.
   - If both asteroids have the same magnitude, both are destroyed.
   - Otherwise, the stack top is larger, so the current asteroid is destroyed.
3. Return the stack.

The important observation is that after an asteroid is destroyed, the new stack top may not be able to collide with the current asteroid anymore. Therefore, the collision condition must be checked inside the `while` loop as well.

## Complexity

- **Time:** `O(n)` amortized
  - Each asteroid is pushed at most once and popped at most once.
- **Space:** `O(n)`
  - In the worst case, all asteroids remain in the stack.

## C++ Solution

```cpp
class Solution {
private:
    bool canCollide(int a, int b) {
        return a > 0 && b < 0;
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            if (!st.empty() && canCollide(st.back(), ast)) {

                while (!st.empty() &&
                       canCollide(st.back(), ast) &&
                       abs(ast) > abs(st.back())) {
                    st.pop_back();
                }

                if (st.empty() || !canCollide(st.back(), ast)) {
                    st.push_back(ast);
                }
                else if (abs(st.back()) == abs(ast)) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(ast);
            }
        }

        return st;
    }
};
