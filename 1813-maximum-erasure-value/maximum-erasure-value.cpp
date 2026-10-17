class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxi = INT_MIN;
        unordered_map<int,bool>mp;
        while(j < nums.size()){
            // agar map me present ho to 
            if(mp.count(nums[j])){
                mp.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            //map me na ho
            else{
                  sum +=nums[j];
                  mp[nums[j]] = true;
                  j++;
                  maxi = max(maxi,sum);
            }
        }
        return maxi;      
    }
};