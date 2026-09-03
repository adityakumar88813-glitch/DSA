class Solution {
public:

    int solve(string &s, string &t, int i, int j,
              vector<vector<int>> &dp) {

        // t completely matched
        if(j < 0) return 1;

        // s finished but t is still remaining
        if(i < 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]) {

            // Take s[i]
            // Don't take s[i]
            return dp[i][j] =
                solve(s, t, i - 1, j - 1, dp) +
                solve(s, t, i - 1, j, dp);
        }

        // Characters different means skip s[i]
        return dp[i][j] =
            solve(s, t, i - 1, j, dp);
    }

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, t, n - 1, m - 1, dp);
    }
};