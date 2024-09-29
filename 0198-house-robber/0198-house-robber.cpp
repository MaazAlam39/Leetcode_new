class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     int z=func(n-1,nums,dp);
        
    //     return z;
        
    // }
    // int func(int ind,vector<int>&nums,vector<int>&dp){
                                                     
    //         if(ind==0)return nums[0];
    //         if(ind<0)return 0; 
    //         if(dp[ind]!=-1)return dp[ind];                                                                                                                                                                                                                                                                                                                                         
    //         int pick=nums[ind]+func(ind-2,nums,dp);
    //         int notpick=0+func(ind-1,nums,dp);
    //         return dp[ind]=max(pick,notpick);
    //     }

    

    int rob(vector<int>& nums) {
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