// class Solution {
// public:
//       int solve(int i , int buy ,int k, vector<int>& prices,vector<vector<vector<int>>> &dp ){
//                int profit = 0;
//                if(i == prices.size()) return 0;
//                if(k==0) return 0;
                 
//                if(dp[i][buy][k] != -1) return dp[i][buy][k];


//                if(buy){
//                 int buyStock = -prices[i] + solve(i+1,0,k,prices,dp);
//                 int skip = solve(i+1,1,k,prices,dp);
//                 profit = max(buyStock,skip);
//                }

//                else{
//                int sellStock = prices[i] + solve(i+1,1,k-1,prices,dp);
//                 int skip = solve(i+1,0,k,prices,dp);
//                 profit = max(sellStock,skip);
//                }
//                return  dp[i][buy][k] = profit ;
//       }
//     int maxProfit(int k, vector<int>& prices) {
//          int n = prices.size();
//          vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(2, vector<int>(k+1, -1))
//         );
//         return solve(0,1,k, prices,dp);
//     }
// };


//Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        // i = n is already 0
        // k = 0 is already 0

        for (int i = n - 1; i >= 0; i--) {

            for (int j = 1; j <= k; j++) {

                // Buy state
                int buyStock =
                    -prices[i] + dp[i + 1][0][j];

                int skipBuy =
                    dp[i + 1][1][j];

                dp[i][1][j] = max(buyStock, skipBuy);


                // Sell state
                int sellStock =
                    prices[i] + dp[i + 1][1][j - 1];

                int skipSell =
                    dp[i + 1][0][j];

                dp[i][0][j] = max(sellStock, skipSell);
            }
        }

        return dp[0][1][k];
    }
};