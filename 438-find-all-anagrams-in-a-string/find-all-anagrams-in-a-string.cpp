class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      if(p.size() > s.size()) return {};
      vector<int>pCount(26,0);
      vector<int>sCount(26,0);
      vector<int>ans;
            
      for(char c : p){
        pCount[c-'a']++;
      }
      
       for(int i = 0 ; i<s.length() ; i++){
        sCount[s[i]-'a']++;

        if(i>=p.length()){
            sCount[s[i-p.length()] - 'a']--;
        }
        if(pCount == sCount){
            ans.push_back(i-p.length() +1);
        }
      }

      return ans;
        
    }
};