class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixSum(n + 1, 0);
        int oddCount = 0;
        int result = 0;
        
        // Calculate prefix sum of odd numbers
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (nums[i] % 2);
        }
        
        // Count subarrays with exactly k odd numbers
        unordered_map<int, int> count;
        count[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            int currentSum = prefixSum[i];
            int target = currentSum - k;
            
            if (count.find(target) != count.end()) {
                result += count[target];
            }
            
            count[currentSum]++;
        }
        
        return result;
    }
};