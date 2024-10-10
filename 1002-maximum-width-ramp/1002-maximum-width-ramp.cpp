class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int max_width = 0;
        int n = nums.size();

        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        // Step 2: Traverse from the right to find the largest ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                int i = st.top();
                st.pop();
                max_width = max(max_width, j - i);
            }
        }

        return max_width;
    }
};