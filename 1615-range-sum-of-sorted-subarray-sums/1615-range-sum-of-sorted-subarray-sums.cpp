class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int arr[n*(n+1)/2];
        for(int i=0,k=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum +=nums[j];
                arr[k++]=sum;
            }
        }
        sort(arr,arr+n*(n+1)/2);
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }
};