class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return minimumSum(0,0,triangle,n,dp);
    }

    int minimumSum(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int bottom=triangle[i][j]+minimumSum(i+1,j,triangle,n,dp);
        int diagonal=triangle[i][j]+minimumSum(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(bottom,diagonal);
    }
};