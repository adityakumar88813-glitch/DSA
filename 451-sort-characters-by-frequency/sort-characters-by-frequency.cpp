

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Create buckets
        vector<vector<char>> bucket(s.size() + 1);

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Build result
        string result = "";
        for (int i = s.size(); i >= 1; i--) {
            for (char c : bucket[i]) {
                result.append(i, c); // repeat char i times
            }
        }

        return result;
    }
};