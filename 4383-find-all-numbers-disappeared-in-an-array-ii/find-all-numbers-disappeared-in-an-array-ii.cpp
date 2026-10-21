class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int>& nums, int lower, int upper) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        int i = 0;

        for (int j = lower; j <= upper; j++) {
            while (i < n && nums[i] < j) {
                i++;
            }

            if (i == n || nums[i] != j) {
                temp.push_back(j);
            } else {
                if (!temp.empty()) {
                    ans.push_back({
                        temp.front(), temp.back()
                    });
                    temp.clear();
                }
                i++;
            }
        }

        if (!temp.empty()) {
            ans.push_back({temp.front(), temp.back()});
        }

        return ans;
    }
};