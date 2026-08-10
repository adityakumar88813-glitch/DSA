class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxReach = 0;

        while(i < n) {
            
            if(i > maxReach)
                return false;

            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= n - 1)
                return true;

            i++;
        }

        return false;
    }
};