class Solution {
public:
    vector<vector<int>> dp;
    int func(int i, int ORS, int maxi, vector<int>& nums) {
        if (i >= nums.size()) {
            return (ORS == maxi) ? 1 : 0;
        }
        if (dp[i][ORS] != -1) {
            return dp[i][ORS];
        }
        int cnt = 0;
        cnt += func(i + 1, ORS | nums[i], maxi, nums); // pick
        cnt += func(i + 1, ORS, maxi, nums); // not pick
        return dp[i][ORS] = cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi |= nums[i];
        }
        dp.assign(n, vector<int>((1 << 17), -1)); // 17 bits assuming nums[i] is within 17 bits
        return func(0, 0, maxi, nums);
    }
};
