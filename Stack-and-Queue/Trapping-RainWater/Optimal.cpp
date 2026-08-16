class Solution {
   public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int leftMax = 0, rightMax = 0;
        int totalVol = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < leftMax) totalVol += leftMax - height[left];
                leftMax = max(leftMax, height[left]);
                left++;
            } else {
                if (height[right] < rightMax)
                    totalVol += rightMax - height[right];
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }

        return totalVol;
    }
};
