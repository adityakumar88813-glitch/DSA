class Solution {
public:
    bool sumGame(string num) {
        int mid = num.length() / 2;

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?') {
                q1++;
            }
            else {
                sum1 += num[i] - '0';
            }
        }

        for (int k = mid; k < num.length(); k++) {
            if (num[k] == '?') {
                q2++;
            }
            else {
                sum2 += num[k] - '0';
            }
        }

        int diff = sum1 - sum2;
        int qdiff = q1 - q2;

        if (qdiff % 2 != 0) {
            return true;
        }

        if (diff == -9 * (qdiff / 2)) {
            return false;
        }

        return true;
    }
};


