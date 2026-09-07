class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        for(char c : s) {
            int idx = c - 'a';

            long long total = 1;

            // All previous subsequences + current character
            for(int j = 0; j < 26; j++) {
                total = (total + dp[j]) % MOD;
            }

            // Replace previous subsequences ending with c
            dp[idx] = total;
        }

        long long ans = 0;

        for(int i = 0; i < 26; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};