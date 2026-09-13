class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        if(n < 2) return 0;
        sort(nums.begin(),nums.end());

        for(int i =n-1 ; i>=1 ; i-- ){
            int diff = nums[i] - nums[i-1];
            maxi = max(maxi,diff);
        }
    return maxi;
    }
};