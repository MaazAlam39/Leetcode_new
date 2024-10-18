class Solution {
public:

    int func(int i,int ORS,int maxi,vector<int>&nums){
        if(i>=nums.size())return (ORS==maxi)?1:0;
        int cnt=0;
        cnt+=func(i+1,ORS | nums[i],maxi,nums);//pick
        cnt+=func(i+1,ORS,maxi,nums);//not pick
        return cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi |=nums[i];
        }
        return func(0,0,maxi,nums);
    }
};