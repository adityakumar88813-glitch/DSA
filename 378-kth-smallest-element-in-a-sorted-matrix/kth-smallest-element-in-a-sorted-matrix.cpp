class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ans;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix.size();j++){
            ans.push_back(matrix[i][j]);
        }
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i<ans.size() ; i++){
            if(i==k-1){
                return ans[i];
            }
        }
        return 0;
    }
};