class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countways(m - 1, n - 1,obstacleGrid, dp);
    }
    int countways(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=countways(i-1,j,obstacleGrid,dp);
        int upwards=countways(i,j-1,obstacleGrid,dp);
        return dp[i][j]=left+upwards;

    }
};