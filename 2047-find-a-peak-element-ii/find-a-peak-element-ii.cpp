class Solution {
public:
       int findMaxElement(vector<int>&row){
        int index = 0;
        for(int i = 0 ; i<row.size() ; i++){
            if(row[i] > row[index]){
                index = i;
            }
        }
        return index;
       }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int low = 0 , high = mat.size()-1;

         while(low<high){
            int mid = low+(high-low)/2;

            int col = findMaxElement(mat[mid]);
            if(mat[mid][col] > mat[mid+1][col]){
                high = mid;

            }
            else{
                low = mid+1;
            }
         }
         int col = findMaxElement(mat[low]);
         return {low,col};
    }
};