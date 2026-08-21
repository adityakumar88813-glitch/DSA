class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxCount = 0, count = 0;
        int i = 0;

        unordered_map<char, int> mp;

        for (int j = i; j < n; j++) {

            mp[s[j]]++;
            count = max(count, mp[s[j]]);

            while ((j - i + 1) - count > k) {
                mp[s[i]]--;
                i++;
            }

            maxCount = max(maxCount, j - i + 1);
        }

        return maxCount;
    }
};