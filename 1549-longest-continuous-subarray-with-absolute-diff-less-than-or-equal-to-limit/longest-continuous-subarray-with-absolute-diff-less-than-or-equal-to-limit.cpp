class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;   // store indices
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            // keep maxD decreasing
            while (!maxD.empty() && nums[maxD.back()] <= nums[right])
                maxD.pop_back();
            maxD.push_back(right);

            // keep minD increasing
            while (!minD.empty() && nums[minD.back()] >= nums[right])
                minD.pop_back();
            minD.push_back(right);

            // shrink window while invalid
            while (nums[maxD.front()] - nums[minD.front()] > limit) {
                left++;
                if (maxD.front() < left) maxD.pop_front();
                if (minD.front() < left) minD.pop_front();
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};