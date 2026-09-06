// class Solution {
// public:

// bool solve(string &s, string &p,int i , int j,  vector<vector<int>> &dp){
//   //base case 

//   // p khatam but s hai 
//    if(j < 0 && i >= 0) return false;

//    // dono consume then sab match 
//    if(i < 0 && j < 0) return true;
 

//  // s khatam but p hai
//   if (i < 0 && j >= 0) {
//             for (int k = 0; k <= j; k++) {
//                 if (p[k] != '*')
//                     return false;
//             }
//             return true;
//         }
    
//     if(dp[i][j] != -1) return dp[i][j];


//   if(p[j] == '*') 
//            return  dp[i][j] = solve(s, p, i, j-1,dp) ||
//                    solve(s, p, i-1, j,dp);


//   if(s[i] == p[j] || p[j] == '?'){
//     return  dp[i][j] = solve(s,p,i-1,j-1,dp);
//   }
//   else
//   return false;
// }
//     bool isMatch(string s, string p) {
//         int n = s.length();
//         int m = p.length();

//         vector<vector<int>> dp(n, vector<int>(m,-1));

//        return solve(s,p,n-1,m-1,dp);


//     }
// };










// TABULAZATION


class Solution {
public:

    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(m + 1, false)
        );

        // Base case
        dp[0][0] = true;

        // s empty hai
        for(int j = 1; j <= m; j++) {

            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        // DP
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // *
                if(p[j-1] == '*') {

                    dp[i][j] =
                        dp[i][j-1] || 
                        dp[i-1][j];

                }

                // same character or ?
                else if(s[i-1] == p[j-1] || p[j-1] == '?') {

                    dp[i][j] =
                        dp[i-1][j-1];

                }

                // mismatch
                else {

                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};