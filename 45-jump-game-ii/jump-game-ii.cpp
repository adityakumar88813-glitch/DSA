class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int maxReach = 0;
        int currentEnd = 0;

        if(n == 1) return 0;

        while(currentEnd < n - 1) {

            maxReach = 0;

            for(int j = i; j <= currentEnd; j++) {
                maxReach = max(maxReach, j + nums[j]);
            }

            count++;

            i = currentEnd + 1;
            currentEnd = maxReach;
        }

        return count;
    }
};