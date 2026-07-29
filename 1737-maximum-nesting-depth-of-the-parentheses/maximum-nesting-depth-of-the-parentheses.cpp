class Solution {
public:
    int maxDepth(string s) {
        int count = 0 , maxCount = 0;
        for(char c = 0 ; c <s.size() ; c++){
            if(s[c]== '(' ){
                count++;
                maxCount = max (count,maxCount);
            }
            else if(s[c]==')'){
                count--;
            }
        }
        return maxCount;
    }
};