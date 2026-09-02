class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        for(int i = 0 ; i <nums1.size() ; i+1){
            if(nums1[i] %2 != 0){
              return true;
            }
        }
        for(int i = 0 ; i <nums1.size() ; i+2){
            if(nums1[i] %2 == 0){
              return true;
            }
        }
        return false;
    }
};