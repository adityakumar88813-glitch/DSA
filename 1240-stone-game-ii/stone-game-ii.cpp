class Solution {
public:

    int dp[101][101];

    int solve(vector<int>& piles, vector<int>& suffix,
              int i, int M) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);

            int opponent =
                solve(piles, suffix, i + X, newM);

            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(piles, suffix, 0, 1);
    }
};