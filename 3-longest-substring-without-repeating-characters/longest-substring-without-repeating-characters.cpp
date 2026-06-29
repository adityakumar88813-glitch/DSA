class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i = 0 ,maxi = 0;
        for(int j = 0; j<s.length(); j++){
            if(m.find(s[j]) != m.end()){
                i  = max(i, m[s[j]]+1);
            }
            m[s[j]] = j;
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};