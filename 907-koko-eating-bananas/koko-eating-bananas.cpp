class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0 ; i < piles.size() ; i++){
            maxi = max(maxi , piles[i]);
        }
        return maxi;
    }

    long long calTime(vector<int>& piles , int hour){
        long long totalM = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            // integer ceil trick (faster + safe)
            totalM += (piles[i] + hour - 1) / hour;
        }

        return totalM;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int high = findMax(piles);

        while(l <= high){
            int mid = l + (high - l) / 2;
            long long totalM = calTime(piles, mid);

            if(totalM <= h){
                high = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};