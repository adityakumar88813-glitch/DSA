class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        int cnt  = 0;
        while(i < nums.size()){
            if(nums[i] != val){
                nums[k] = nums[i];
                cnt++;
                i++;
                k++;
            }
            else{
                i++;
            }
        }
        return k;
    }
};