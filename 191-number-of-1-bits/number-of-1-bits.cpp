class Solution {
public:
    string result = "";

    string DecimalToBinary(int n) {
        while (n > 0) {
            if (n % 2 == 1)
                result += '1';
            else
                result += '0';

            n /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int hammingWeight(int n) {
        result = "";
        int count = 0;

        DecimalToBinary(n);

        for (int i = 0; i < result.length(); i++) {
            if (result[i] == '1')
                count++;
        }

        return count;
    }
};