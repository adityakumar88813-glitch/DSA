class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        // Count in how many k-sized windows each number appears
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        for (auto [x, cnt] : freq) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};