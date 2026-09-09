// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int total_profit = 0;

//         for(int i = 0; i < n - 1; i++) {
//             if(prices[i] < prices[i + 1]) {
//                 total_profit += prices[i + 1] - prices[i];
//             }
//         }

//         return total_profit;
//     }
// };




// USING DP
 
//  class Solution {
// public:

//     int solve(int i, int buy, vector<int>& prices ,  vector<vector<int>> &dp) {
//         // Base case
//         if (i == prices.size())
//             return 0;
//         int profit = 0;

//         if(dp[i][buy] != -1) return dp[i][buy];

//         if (buy) {
//             // Buy
//             int buyStock = -prices[i] + solve(i + 1, 0, prices,dp);

//             // Skip buying
//             int skip = solve(i + 1, 1, prices ,dp);

//             profit = max(buyStock, skip);
//         }
//         else {
//             // Sell
//             int sellStock = prices[i] + solve(i + 1, 1, prices,dp);

//             // Skip selling
//             int skip = solve(i + 1, 0, prices,dp);

//             profit = max(sellStock, skip);
//         }

//         return dp[i][buy]  =  profit;
//     }

//     int maxProfit(vector<int>& prices) {
//          int n = prices.size();
//          vector<vector<int>> dp(n , vector<int>(2,-1));
//         return solve(0, 1, prices ,dp);
//     }
// };



//TABULATION
// class Solution {
// public:

//     int maxProfit(vector<int>& prices) {
//          int n = prices.size();
      
//          vector<vector<int>> dp(n+1 , vector<int>(2,0));
//          //BASE CASE
//          dp[n][0] = dp[n][1] = 0;
//          for(int i = n-1 ; i >= 0 ; i--){
//             for(int buy = 0 ; buy <=1 ; buy++){
//                  if (buy) {
//             // Buy
//             int buyStock = -prices[i] + dp[i+1][0];

//             // Skip buying
//             int skip = dp[i+1][1];

//               dp[i][buy] = max(buyStock, skip);
//         }
//         else {
//             // Sell
//             int sellStock = prices[i] + dp[i+1][1];

//             // Skip selling
//             int skip = dp[i+1][0];

//                dp[i][buy] = max(sellStock, skip);
//         }

       
//             }
//          }
//             return dp[0][1];
//     }
// };

//SPCAE

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // ahead = dp[i+1]
        // curr  = dp[i]
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        // Base case
        ahead[0] = ahead[1] = 0;

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                if (buy) {

                    // Buy
                    int buyStock = -prices[i] + ahead[0];

                    // Skip buying
                    int skip = ahead[1];

                    curr[buy] = max(buyStock, skip);
                }

                else {

                    // Sell
                    int sellStock = prices[i] + ahead[1];

                    // Skip selling
                    int skip = ahead[0];

                    curr[buy] = max(sellStock, skip);
                }
            }

            // Current row becomes ahead for next iteration
            ahead = curr;
        }

        return ahead[1];
    }
};