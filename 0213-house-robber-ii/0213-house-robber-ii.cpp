class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(linear_rob(temp1),linear_rob(temp2));
    }
    int linear_rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notake=0+prev;
            int cur_i=max(take,notake);
            prev2=prev;
            prev=cur_i;
        }
        return prev;
        
    }
};