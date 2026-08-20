class Solution { 
public: 
    int totalFruit(vector<int>& fruits) { 
        int dis = 0; 
        int n = fruits.size(); 
        int i = 0; 
        int maxCount = 0; 
        
        unordered_map<int, int> mp;

        for(int j = 0; j < n; j++) { 
            
            mp[fruits[j]]++;
            
            if(mp[fruits[j]] == 1) {
                dis++;
            }

            while(dis > 2) { 
                mp[fruits[i]]--;

                if(mp[fruits[i]] == 0) {
                    dis--;
                }

                i++;
            }

            maxCount = max(maxCount, j - i + 1);
        } 

        return maxCount; 
    } 
};