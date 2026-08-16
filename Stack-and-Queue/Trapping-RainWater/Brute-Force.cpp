class Solution {
   private:
    vector<int> NGE(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> find_SuffixMaxIdx(vector<int>& nums) {
        int n = nums.size();
        vector<int> SuffixMaxIdx(n);

        SuffixMaxIdx[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[SuffixMaxIdx[i + 1]])
                SuffixMaxIdx[i] = i;
            else
                SuffixMaxIdx[i] = SuffixMaxIdx[i + 1];
        }

        return SuffixMaxIdx;
    }

   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nge = NGE(height);
        vector<int> SuffixMaxIdx = find_SuffixMaxIdx(height);
        int totalVol = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i == 0 && height[i] == 0) continue;
            if (nge[i] == -1) {
                int cand = SuffixMaxIdx[i + 1];
                if (height[cand] == 0) continue;
                nge[i] = cand;
            }
            int waterlevel = min(height[i], height[nge[i]]);
            
            totalVol += (nge[i] - i - 1) * waterlevel;
            int j;
            for (j = i + 1; j < nge[i]; j++) totalVol -= height[j];
            i = j - 1;
        }

        return totalVol;
    }
};
