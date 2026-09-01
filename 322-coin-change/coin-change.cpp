class Solution {
public:
    int solve(vector<int>& coins, int i, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (i == coins.size())
            return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Don't take the coin
        int nottake = solve(coins, i + 1, amount, dp);

        // Take the coin
        int take = 1e9;

        if (coins[i] <= amount) {
            take = 1 + solve(coins, i, amount - coins[i], dp);
        }

        return dp[i][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};