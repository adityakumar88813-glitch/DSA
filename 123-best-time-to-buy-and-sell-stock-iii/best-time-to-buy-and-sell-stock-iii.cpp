class Solution {
public:

int solve(int i, int buy, vector<int>& prices ,  vector<vector<vector<int>>> &dp , int cap) {
        // Base case
        if (i == prices.size()) return 0;
        if(cap == 0) return 0; 
            
        int profit = 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if (buy) {
            // Buy
            int buyStock = -prices[i] + solve(i + 1, 0, prices,dp ,cap);

            // Skip buying
            int skip = solve(i + 1, 1, prices ,dp ,cap);

            profit = max(buyStock, skip);
        }
        else {
            // Sell
            int sellStock = prices[i] + solve(i + 1, 1, prices,dp,cap-1);

            // Skip selling
            int skip = solve(i + 1, 0, prices,dp ,cap);

            profit = max(sellStock, skip);
        }

        return dp[i][buy][cap]  =  profit;
}

    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );
        return solve(0, 1, prices ,dp ,2 );
    }
};