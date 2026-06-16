class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;

        for (long long x = 1; x * (x + 1) / 2 <= n; x++) {
            long long v = x * (x + 1) / 2;

            if ((n - v) % x == 0) {
                ans++;
            }
        }

        return ans;
    }
};