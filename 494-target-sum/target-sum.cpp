class Solution {
public:
    int solve(vector<int>& nums, int i, int target,
              vector<vector<int>>& dp, int total) {

        if (i < 0)
            return target == 0;
          if (target > total || target < -total)
            return 0;
        int index = target + total;

        if (dp[i][index] != -1)
            return dp[i][index];

        int add = solve(nums, i - 1,
                        target + nums[i], dp, total);

        int subtract = solve(nums, i - 1,
                             target - nums[i], dp, total);

        return dp[i][index] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = 0;
        for (auto x : nums)
            total += x;

        if (target > total || target < -total)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(nums, n - 1, target, dp, total);
    }
};