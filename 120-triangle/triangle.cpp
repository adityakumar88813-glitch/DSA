class Solution {
public:
       int solve(int row , int col ,vector<vector<int>>& triangle , int n , vector<vector<int>> &dp){
            if( row == n-1) return triangle[n-1][col];
            if(dp[row][col] != INT_MAX) return dp[row][col];
            int down = triangle[row][col] + solve(row + 1,col,triangle ,n ,dp);
            int diagonal =  triangle[row][col] + solve(row+1,col+1 ,triangle ,n ,dp) ;
            dp[row][col] = min(down,diagonal);
            return dp[row][col];
       }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
       
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        return solve(0, 0,triangle , n ,dp);
    }
};