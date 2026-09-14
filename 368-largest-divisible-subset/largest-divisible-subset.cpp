// class Solution {
// public:
//     vector<int> solve(int i, vector<int>& nums, int pre) {

//         if (i == nums.size())
//             return {};

//         // Don't take
//         vector<int> notTake = solve(i + 1, nums, pre);

//         // Take
//         vector<int> take;

//         if (pre == -1 || nums[i] % nums[pre] == 0) {
//             take = solve(i + 1, nums, i);
//             take.push_back(nums[i]);
//         }

//         if (take.size() > notTake.size())
//             return take;

//         return notTake;
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         return solve(0, nums, -1);
//     }
// };




class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0) {

                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;

        while (lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};