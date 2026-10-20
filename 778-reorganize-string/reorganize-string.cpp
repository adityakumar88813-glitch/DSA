// class Solution {
// public:
//     string reorganizeString(string s) {
//        int n = s.size();
//         int j = 0;
//         for(int i = 0; i <n-1; i++){
//             if(s[i] == s[i+1]){
//                 j = i+2;
//                  while (j < n && s[j] == s[i]) {
//                     j++;
//                 }
//             }
//             if(j==n) return "";
//             swap(s[i+1],s[j]);
//         }
//         return s;
//     }
// };



class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > (n + 1) / 2) {
                return "";
            }

            if (freq[i] > 0) {
                pq.push({freq[i], char('a' + i)});
            }
        }

        string ans = "";

        while (pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if (first.first > 0) pq.push(first);
            if (second.first > 0) pq.push(second);
        }

        if (!pq.empty()) {
            ans += pq.top().second;
        }

        return ans;
    }
};
