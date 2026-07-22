class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum = 0;
       int maxi = nums[0];

       for(int i = 0; i<nums.size();i++){
        //1st step 
        sum  = sum + nums[i];
        //2nd step
        maxi = max(maxi , sum);

        //3rd 
        if(sum<0){
            sum = 0;
        }

       }
       return maxi;
    }
};