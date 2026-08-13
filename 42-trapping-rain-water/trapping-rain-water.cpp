class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = 0, rMax = 0 , total = 0;
        int left = 0, right = n-1;

        while(left<right){
              //left smalll ho to usme operation
            if(height[left] < height[right]){
                if(lMax > height[left]){
                    total+= lMax - height[left];
                }
                else{
                    lMax = height[left];
                   
                }
                 left+= 1;
            }
            //right smalll ho to usme operation

            else{
                 if(rMax > height[right]){
                    total+= rMax - height[right];
                }
                else{
                    rMax = height[right];
                   
                }
                 right -= 1;
            

            }
        }
        return total;
    }
};