class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        vector<int> pse(n);

        vector<int> st;

        //find nse
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] >= nums[i]) st.pop_back();
            nse[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        st.clear();
        //find pse
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) st.pop_back();
            pse[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            sum += 1LL * left * right * nums[i];
        }

        return sum % 1000000007;
    }
};
