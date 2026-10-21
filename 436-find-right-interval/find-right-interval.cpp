class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;

            for (int j = 0; j < n; j++) {
                if ( intervals[j][0] >= intervals[i][1]) {
                    if (intervals[j][0] < mini) {
                        mini = intervals[j][0];
                        ans[i] = j;
                    }
                }
            }
        }

        return ans;
    }
};