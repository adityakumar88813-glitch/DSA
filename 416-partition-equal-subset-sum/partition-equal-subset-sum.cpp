class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, int target, vector<vector<int>> &dp) {
        
        if(sum == target)
            return true;
        
        if(i == nums.size() || sum > target)
            return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        // Take current element
        if(solve(nums, i + 1, sum + nums[i], target,dp))
            return dp[i][sum] = true;
        
        // Don't take current element
        return dp[i][sum] = solve(nums, i + 1, sum, target,dp);
    }

    bool canPartition(vector<int>& nums) {
       
                              
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
         vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, 0, 0, target ,dp);
    }
};