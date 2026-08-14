class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int maxLength = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.length(); r++) {

            freq[s[r] - 'a']++;

            // Any character occurs more than 2 times
            while (freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};