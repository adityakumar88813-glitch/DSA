
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        vector<int> ans(deck.size());  // Fix 1
        queue<int> q;

        int n = deck.size();

        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        for (int card : deck) {
            ans[q.front()] = card;
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};
