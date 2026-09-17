class Solution {
public:
int solve(int index ,vector<int>& arr, int k ,  vector<int> &dp){
    int n = arr.size();
    int maxi  = INT_MIN;
    int maxAns = INT_MIN;
    int len = 0 ,sum = 0;

    //base case
    if(index == n) return 0;

    if(dp[index] != -1) return dp[index];

    for(int j = index ; j < min(index+k,n) ; j++){
            len++;
            //max element find
            maxi = max(maxi,arr[j]);
            //sum
            sum = len*maxi + solve(j+1,arr,k,dp);
            //maximum ans
            maxAns = max(maxAns , sum);
    }
 return  dp[index] = maxAns;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};