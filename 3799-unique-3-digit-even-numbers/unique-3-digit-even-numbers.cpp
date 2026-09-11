class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int cnt[10] = {};

        for(int x : digits)
            cnt[x]++;

        int ans = 0;

        for(int i = 1; i <= 9; i++) {
            if(cnt[i] == 0) continue;

            for(int j = 0; j <= 9; j++) {
                if(cnt[j] == 0) continue;

                for(int k = 0; k <= 8; k += 2) {
                    if(cnt[k] == 0) continue;

                    // Same digit used more than available copies
                    if(i == j && cnt[i] < 2) continue;

                    if(i == k && cnt[i] < 2) continue;

                    if(j == k && cnt[j] < 2) continue;

                    if(i == j && j == k && cnt[i] < 3) continue;

                    ans++;
                }
            }
        }

        return ans;
    }
};