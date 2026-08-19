class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        priority_queue<pair<int, int>> pq;

        // First window
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        // Remaining windows
        for (int i = k; i < n; i++) {

            pq.push({nums[i], i});

            // Remove elements outside the window
            while (pq.top().second <= i - k) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};