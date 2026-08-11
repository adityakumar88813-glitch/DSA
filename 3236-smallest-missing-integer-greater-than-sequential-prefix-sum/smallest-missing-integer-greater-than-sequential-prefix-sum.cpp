class Solution {
public:
    int missingInteger(vector<int>& nums) {
         int n = nums.size();
          int sum = 0;
         int index = n;
         for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1] != nums[i] +1){
                index = i+1;
                break;
            }
         }
        
         for(int i = 0 ; i <index ; i++){
            sum+=nums[i];
         }
         
         unordered_set<int> st;
         for(int x:nums){
            st.insert(x);
         }
         while(st.count(sum)){
            sum++;
         }
         return sum;
    }
};