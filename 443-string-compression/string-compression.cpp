class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int write = 0;

        while (i < n) {
            char ch = chars[i];
            int cnt = 0;

            // Count consecutive characters
            while (i < n && chars[i] == ch) {
                cnt++;
                i++;
            }

            // Write character
            chars[write++] = ch;

            // Write count
            if (cnt > 1) {
                string s = to_string(cnt);

                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};