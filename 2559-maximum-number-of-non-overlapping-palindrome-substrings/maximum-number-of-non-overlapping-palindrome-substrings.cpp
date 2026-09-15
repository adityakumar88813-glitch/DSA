class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // pal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len <= 2)
                        pal[i][j] = true;

                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = maximum answer from index i onward
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't take
            dp[i] = dp[i + 1];

            // Take s[i...j]
            for (int j = i + k - 1; j < n; j++) {

                if (pal[i][j]) {

                    dp[i] = max(
                        dp[i],
                        1 + dp[j + 1]
                    );
                }
            }
        }

        return dp[0];
    }
};