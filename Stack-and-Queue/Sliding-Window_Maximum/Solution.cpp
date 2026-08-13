class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);

        if (dq.front() == 0)
            dq.pop_front();

        int left = 1, right = k;

        while (right < n) {
            while (!dq.empty() && nums[right] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(right);

            result.push_back(nums[dq.front()]);

            if (dq.front() == left)
                dq.pop_front();

            left++;
            right++;
        }

        return result;
    }
};
