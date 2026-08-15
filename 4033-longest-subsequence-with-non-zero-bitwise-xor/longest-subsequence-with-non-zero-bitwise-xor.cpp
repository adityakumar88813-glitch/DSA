// class Solution {
// public:
//     int longestSubsequence(vector<int>& nums) {
//         int maxLength = 0;
//         int n = nums.size();
//         int i = 0;
//         for(int j = 0 ; j <n ; j++){
//             if(nums[i] ^ nums[j] != 0){
//                 maxLength = max(maxLength , abs(j-i+1));
//             }
//             else{
//                 i++;
//             }
//         } 
//         return maxLength;
//     }
// };

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
        }

        // Whole array ka XOR non-zero hai
        if(xr != 0) {
            return n;
        }

        // XOR zero hai, koi non-zero element remove kar sakte hain
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                return n - 1;
            }
        }

        // Saare elements zero hain
        return 0;
    }
};