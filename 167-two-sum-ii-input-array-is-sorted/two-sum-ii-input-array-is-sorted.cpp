class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0 , end = n-1;
        while(start < end){
            if(numbers[start] + numbers[end] > target){
              end = end-1;
            }
            else if(numbers[start] + numbers[end] < target){
                start = start+1;
            }
            else{
                return{start+1,end+1};
            }
        }
          return{-1,-1};
    }
};