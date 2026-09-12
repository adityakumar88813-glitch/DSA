class Solution {
public:
int solve(int i , int buy ,vector<int>& prices, vector<vector<int>> &dp,int fee){
    int profit = 0;
    if (i == prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
       if (buy) {
            // Buy
            int buyStock = -prices[i] + solve(i + 1, 0, prices,dp,fee);

            // Skip buying
            int skip = solve(i + 1, 1, prices,dp,fee);

            profit = max(buyStock, skip);
        }
        else {
            // Sell
            int sellStock = prices[i]-fee + solve(i + 1, 1, prices,dp,fee);

            // Skip selling
            int skip = solve(i + 1, 0, prices,dp,fee);

            profit = max(sellStock, skip);
        }

        return dp[i][buy] = profit;
    }



    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
    }
};