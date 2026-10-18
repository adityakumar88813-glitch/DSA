class Solution {
public:
 void solve(int i, int n , int k, vector<int>&temp,  vector<vector<int>>&ans){
           
          if(temp.size()==k){
            ans.push_back(temp);
            return;
          }
          for(int j = i ; j<=n ; j++){
             
             //take
             temp.push_back(j);

             //next
             solve(j+1,n,k,temp,ans);

             //backtracking
             temp.pop_back();
          }
            
    
 }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
            vector<int>temp;
            solve(1,n,k,temp , ans);
            return ans;
    }
};