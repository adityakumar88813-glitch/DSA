class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);

       sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) < abs(b); });

        int left = 0;
        int right =n-1;

        for(int i = 0; i<n ; i++){
            if(i%2==0){
                temp[i] = nums[right];
                right--;
            }
            else{
                temp[i] = nums[left];
                left++;
            }
        }

          long long ans = 0;

        for(int i = 0 ; i<n ; i++){
            long long square = 1LL * temp[i] * temp[i];
                if( i%2 ==0){
                    ans = ans + square;
                }
                else{
                     ans = ans - square;
                }
        }
        return ans;
    }
};