class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       int count = 1;
       int maxCount = 1;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] < nums[i+1]){
                count++;
            }
            else{
                count = 1;
            }
              maxCount =  max(count , maxCount);
        }
      return maxCount;
    }
};